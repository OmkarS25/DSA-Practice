class Router {
    struct Packet {
        int source, destination, timestamp;
    };

    int MaxSize;
    queue<Packet> q;
    unordered_set<string> packetSet;
    unordered_map<int, vector<int>> destTimeMap;

    string makeKey(int source, int destination, int timestamp) {
        return to_string(source) + "#" + to_string(destination) + "#" + to_string(timestamp);
    }

public:
    Router(int memoryLimit) : MaxSize(memoryLimit) {}

    bool addPacket(int source, int destination, int timestamp) {
        string key = makeKey(source, destination, timestamp);
        if (packetSet.count(key)) return false;

        if (q.size() >= MaxSize) {
            Packet old = q.front(); q.pop();
            string oldKey = makeKey(old.source, old.destination, old.timestamp);
            packetSet.erase(oldKey);

            auto& vec = destTimeMap[old.destination];
            vec.erase(lower_bound(vec.begin(), vec.end(), old.timestamp));
        }

        Packet p = {source, destination, timestamp};
        q.push(p);
        packetSet.insert(key);
        destTimeMap[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if (q.empty()) return {};

        Packet p = q.front(); q.pop();
        string key = makeKey(p.source, p.destination, p.timestamp);
        packetSet.erase(key);

        auto& vec = destTimeMap[p.destination];
        vec.erase(lower_bound(vec.begin(), vec.end(), p.timestamp));

        return {p.source, p.destination, p.timestamp};
    }

    int getCount(int destination, int startTime, int endTime) {
        auto& vec = destTimeMap[destination];
        auto startIt = lower_bound(vec.begin(), vec.end(), startTime);
        auto endIt = upper_bound(vec.begin(), vec.end(), endTime);
        return endIt - startIt;
    }
};
