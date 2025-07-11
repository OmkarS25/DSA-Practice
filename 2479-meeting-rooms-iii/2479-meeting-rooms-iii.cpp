class Solution {
public:
    int mostBooked(int nm, vector<vector<int>>& meets) {
        int n = meets.size(); 
        vector<tuple<int, int, int>> vt;

        // Store (start_time, end_time, index)
        for (int i = 0; i < n; ++i) {
            vt.push_back({meets[i][0], meets[i][1], i});
        }

        // Sort meetings by start time
        sort(vt.begin(), vt.end());

        // Priority queue to track available rooms (min-heap by room number)
        priority_queue<int, vector<int>, greater<int>> freeRooms;
        for (int i = 0; i < nm; ++i) {
            freeRooms.push(i);
        }

        // Priority queue to track ongoing meetings: (end_time, room_id)
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busyRooms;

        vector<int> count(nm); // number of meetings per room

        for (auto &[stt, endd, idx] : vt) {
            // Free up rooms that have finished by current start time
            while (!busyRooms.empty() && busyRooms.top().first <= stt) {
                int room = busyRooms.top().second;
                busyRooms.pop();
                freeRooms.push(room);
            }

            int duration = endd - stt;

            if (!freeRooms.empty()) {
                int room = freeRooms.top(); freeRooms.pop();
                count[room]++;
                busyRooms.push({endd, room});
            } else {
                auto [fin_time, room] = busyRooms.top(); busyRooms.pop();
                count[room]++;
                busyRooms.push({fin_time + duration, room});
            }
        }

        // Find room with max meetings, tie → lowest room number
        int ans = 0;
        for (int i = 1; i < nm; ++i) {
            if (count[i] > count[ans]) {
                ans = i;
            }
        }
        return ans;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();