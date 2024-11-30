class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>> adj;
        unordered_map<int,int> deg;

        // build graph and count in/out degress
        for(const auto& it: pairs){
            int start = it[0], end = it[1];
            adj[start].push_back(end);
            deg[start]++; //out-degree
            deg[end]--; // in-degree
        }

        // find start node
        int startnode = pairs[0][0];
        for(const auto& it: deg){ // it = {node,degree}
            if(it.second==1){
                startnode = it.first;
                break;
            }
        }

        vector<int> path;
        stack<int> nodest; // node stack
        nodest.push(startnode);

        while(!nodest.empty()){
            auto& neighbors = adj[nodest.top()];
            if(neighbors.empty()){
                path.push_back(nodest.top());
                nodest.pop();
            }
            else{
                int nextnode = neighbors.back();
                nodest.push(nextnode);
                neighbors.pop_back();
            }
        }
        vector<vector<int>> arrangement;
        int pathsize = path.size();
        arrangement.reserve(pathsize-1);
        
        for(int i= pathsize-1; i>0;i--){
            arrangement.push_back({path[i],path[i-1]});
        }

        return arrangement;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();