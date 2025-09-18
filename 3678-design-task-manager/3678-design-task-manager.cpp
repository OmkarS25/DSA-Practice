class TaskManager {
public:
    unordered_map<int, pair<int, int>> mpp;
    priority_queue<pair<int, int>> pq;

    TaskManager(vector<vector<int>>& tasks) {
        for(auto& task : tasks){
            mpp[task[1]] = {task[2], task[0]};
            pq.push({task[2], task[1]});
        }    
    }
    
    void add(int userId, int taskId, int priority) {
        mpp[taskId] = {priority, userId};
        pq.push({priority, taskId});
    }
    
    void edit(int taskId, int newPriority) {
        mpp[taskId].first = newPriority;
        pq.push({newPriority, taskId});
    }
    
    void rmv(int taskId) {
        mpp[taskId].first = -1;
    }
    
    int execTop() {
        while(!pq.empty()){
            auto [priority, taskId] = pq.top();

            if(mpp[taskId].first == priority){
                mpp[taskId].first = -1;
                pq.pop();
                return mpp[taskId].second;
            }
            else{
                pq.pop();
            }
        }

        return -1;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();

// class TaskManager {
//     // modified C-array version
//     using int2 = pair<int, int>;
//     int2 mp[100001]; // taskID->(prioity, userId)
//     // int maxI = -1;
//     priority_queue<int2> pq; //(priority, taskID)

// public:
//     TaskManager(vector<vector<int>>& tasks) {
//         // fill(mp, mp+100001, make_pair(-1, -1));
//         for (auto& t : tasks) {
//             int u = t[0], i = t[1], p = t[2];
//             // maxI = max(maxI, i);
//             mp[i] = {p, u};
//             pq.emplace(p, i);
//         }
//     }

//     // ~TaskManager() { memset(mp, -1, 8 * (maxI + 1)); }

//     void add(int userId, int taskId, int priority) {
//         mp[taskId] = {priority, userId};
//         pq.emplace(priority, taskId);
//     }

//     void edit(int taskId, int newPriority) {
//         mp[taskId].first = newPriority;
//         pq.emplace(newPriority, taskId);
//     }

//     void rmv(int taskId) { mp[taskId].first = -1; }

//     int execTop() {
//         while (!pq.empty()) {
//             auto [p, i] = pq.top();
//             if (mp[i].first == p) {
//                 pq.pop();
//                 int u = mp[i].second;
//                 mp[i] = {-1, -1}; // Remove task after execution
//                 return u;
//             }
//             pq.pop(); // Remove
//         }
//         return -1; // No valid tasks to execute
//     }
// };

// #pragma GCC optimize ("O3", "unroll-loops")
// static const int _=[]()noexcept{
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     return 0;
// }();