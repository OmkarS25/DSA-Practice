class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> res(n), graph(n);
        for(const auto& edge: edges){
            graph[edge[0]].push_back(edge[1]);
        }                
        for(int i=0; i<n; i++){
            vector<bool> visit(n, false);
            dfs(graph, i, i, res, visit);
        }
        for(int i=0; i<n; i++){
            sort(res[i].begin(), res[i].end());
        }
        return res;
    }
private:
    void dfs(vector<vector<int>>& graph, int parent, int curr, 
    vector<vector<int>>& res, vector<bool>& visit){
        visit[curr] = true;
        for(int dest: graph[curr]){
            if(!visit[dest]){
                res[dest].push_back(parent);
                dfs(graph, parent, dest, res, visit);
            }
        }
    }
};

// Testcases
/*52
[[30,3],[30,43],[30,23],[30,15],[30,20],[30,45],[30,26],[30,48],[30,38],[30,27],[30,10],[30,51],[30,8],[30,16],[30,39],[30,9],[30,47],[30,29],[30,13],[30,4],[30,18],[30,31],[30,17],[30,35],[30,11],[30,33],[30,46],[30,19],[30,24],[30,12],[30,50],[30,5],[30,21],[30,2],[30,34],[30,25],[30,36],[3,43],[3,14],[3,23],[3,15],[3,20],[3,45],[3,26],[3,48],[3,37],[3,27],[3,0],[3,28],[3,8],[3,16],[3,39],[3,9],[3,47],[3,6],[3,4],[3,18],[3,22],[3,35],[3,7],[3,46],[3,12],[3,5],[3,49],[3,21],[3,2],[3,34],[3,44],[43,23],[43,15],[43,42],[43,20],[43,45],[43,48],[43,38],[43,37],[43,40],[43,10],[43,28],[43,51],[43,16],[43,39],[43,9],[43,13],[43,18],[43,31],[43,22],[43,17],[43,11],[43,41],[43,33],[43,7],[43,46],[43,19],[43,24],[43,12],[43,50],[43,5],[43,21],[43,2],[43,34],[43,25],[43,44],[14,23],[14,1],[14,15],[14,42],[14,20],[14,45],[14,26],[14,48],[14,27],[14,40],[14,0],[14,10],[14,51],[14,8],[14,39],[14,47],[14,29],[14,6],[14,22],[14,17],[14,35],[14,11],[14,7],[14,46],[14,19],[14,24],[14,12],[14,50],[14,5],[14,49],[14,34],[14,32],[14,44],[23,1],[23,20],[23,45],[23,26],[23,38],[23,37],[23,27],[23,0],[23,10],[23,8],[23,39],[23,9],[23,47],[23,13],[23,6],[23,4],[23,18],[23,31],[23,22],[23,17],[23,35],[23,11],[23,41],[23,7],[23,12],[23,5],[23,2],[23,34],[23,32],[23,25],[23,36],[23,44],[1,42],[1,20],[1,45],[1,48],[1,37],[1,40],[1,51],[1,8],[1,16],[1,47],[1,4],[1,18],[1,31],[1,17],[1,11],[1,41],[1,33],[1,24],[1,12],[1,50],[1,5],[1,49],[1,21],[1,34],[1,32],[1,36],[1,44],[15,42],[15,45],[15,38],[15,27],[15,40],[15,10],[15,28],[15,8],[15,16],[15,9],[15,47],[15,29],[15,13],[15,18],[15,22],[15,17],[15,35],[15,41],[15,33],[15,46],[15,19],[15,12],[15,49],[15,2],[15,34],[15,32],[15,36],[42,45],[42,48],[42,38],[42,27],[42,40],[42,0],[42,28],[42,51],[42,16],[42,39],[42,9],[42,47],[42,29],[42,13],[42,6],[42,4],[42,18],[42,31],[42,35],[42,11],[42,41],[42,19],[42,24],[42,50],[42,5],[42,49],[42,21],[42,2],[42,32],[42,25],[20,45],[20,38],[20,37],[20,40],[20,10],[20,28],[20,51],[20,8],[20,39],[20,29],[20,13],[20,6],[20,4],[20,17],[20,35],[20,41],[20,33],[20,7],[20,12],[20,50],[20,5],[20,49],[20,34],[20,32],[20,36],[20,44],[45,26],[45,38],[45,37],[45,27],[45,40],[45,10],[45,28],[45,51],[45,8],[45,16],[45,39],[45,9],[45,47],[45,29],[45,13],[45,6],[45,4],[45,31],[45,17],[45,35],[45,11],[45,33],[45,7],[45,46],[45,24],[45,12],[45,50],[45,49],[45,2],[45,34],[45,25],[45,36],[45,44],[26,38],[26,27],[26,40],[26,0],[26,10],[26,8],[26,16],[26,39],[26,47],[26,29],[26,13],[26,6],[26,18],[26,31],[26,22],[26,35],[26,41],[26,46],[26,19],[26,49],[26,34],[26,32],[26,36],[26,44],[48,37],[48,0],[48,28],[48,51],[48,16],[48,39],[48,9],[48,29],[48,6],[48,4],[48,18],[48,31],[48,35],[48,41],[48,33],[48,7],[48,46],[48,19],[48,12],[48,5],[48,49],[48,25],[48,36],[48,44],[38,27],[38,40],[38,10],[38,51],[38,16],[38,9],[38,47],[38,29],[38,6],[38,18],[38,31],[38,22],[38,11],[38,41],[38,33],[38,7],[38,19],[38,24],[38,50],[38,5],[38,49],[38,21],[38,2],[38,32],[38,44],[37,27],[37,40],[37,10],[37,28],[37,8],[37,16],[37,39],[37,9],[37,4],[37,18],[37,31],[37,22],[37,17],[37,41],[37,33],[37,46],[37,12],[37,50],[37,5],[37,2],[37,34],[37,44],[27,10],[27,51],[27,8],[27,39],[27,9],[27,29],[27,13],[27,6],[27,4],[27,18],[27,22],[27,17],[27,41],[27,33],[27,46],[27,19],[27,12],[27,2],[27,34],[27,32],[27,36],[27,44],[40,0],[40,10],[40,28],[40,8],[40,39],[40,9],[40,47],[40,29],[40,13],[40,4],[40,18],[40,22],[40,17],[40,35],[40,11],[40,41],[40,33],[40,7],[40,46],[40,19],[40,49],[40,21],[40,34],[40,32],[40,25],[40,44],[0,10],[0,8],[0,16],[0,39],[0,9],[0,6],[0,4],[0,35],[0,11],[0,41],[0,46],[0,19],[0,12],[0,49],[0,21],[0,2],[0,34],[0,32],[0,25],[0,36],[0,44],[10,28],[10,51],[10,8],[10,39],[10,47],[10,29],[10,4],[10,18],[10,31],[10,22],[10,17],[10,35],[10,11],[10,41],[10,33],[10,7],[10,19],[10,12],[10,50],[10,49],[10,21],[10,2],[10,34],[10,32],[10,25],[10,44],[28,51],[28,8],[28,9],[28,29],[28,13],[28,4],[28,18],[28,17],[28,35],[28,11],[28,41],[28,33],[28,7],[28,46],[28,19],[28,24],[28,50],[28,5],[28,49],[28,21],[28,2],[28,34],[28,25],[28,36],[51,8],[51,16],[51,47],[51,13],[51,6],[51,4],[51,18],[51,31],[51,17],[51,35],[51,11],[51,19],[51,24],[51,50],[51,49],[51,2],[51,34],[51,25],[51,44],[8,16],[8,39],[8,47],[8,29],[8,13],[8,6],[8,22],[8,17],[8,35],[8,41],[8,33],[8,46],[8,19],[8,50],[8,49],[8,21],[8,2],[8,34],[8,32],[8,25],[8,36],[8,44],[16,39],[16,9],[16,47],[16,29],[16,13],[16,6],[16,4],[16,18],[16,31],[16,11],[16,41],[16,33],[16,7],[16,46],[16,19],[16,24],[16,12],[16,50],[16,5],[16,49],[16,21],[16,2],[16,34],[16,32],[16,25],[16,36],[39,9],[39,47],[39,29],[39,13],[39,6],[39,4],[39,18],[39,31],[39,22],[39,35],[39,11],[39,41],[39,46],[39,24],[39,50],[39,5],[39,49],[39,21],[39,2],[39,32],[39,36],[39,44],[9,47],[9,29],[9,4],[9,18],[9,22],[9,35],[9,11],[9,41],[9,33],[9,7],[9,12],[9,21],[9,2],[9,34],[9,25],[9,36],[9,44],[47,13],[47,6],[47,31],[47,22],[47,17],[47,35],[47,11],[47,41],[47,33],[47,46],[47,19],[47,24],[47,12],[47,50],[47,49],[47,2],[47,32],[47,25],[47,36],[29,4],[29,31],[29,22],[29,41],[29,33],[29,7],[29,19],[29,24],[29,12],[29,50],[29,5],[29,21],[29,2],[29,34],[29,32],[29,25],[29,44],[13,6],[13,4],[13,18],[13,31],[13,22],[13,17],[13,35],[13,11],[13,41],[13,33],[13,7],[13,19],[13,12],[13,50],[13,5],[13,21],[13,2],[13,32],[13,25],[13,44],[6,18],[6,31],[6,22],[6,17],[6,41],[6,7],[6,19],[6,24],[6,5],[6,21],[6,36],[6,44],[4,18],[4,31],[4,17],[4,35],[4,11],[4,41],[4,7],[4,46],[4,19],[4,24],[4,5],[4,49],[4,2],[4,34],[4,32],[4,44],[18,31],[18,17],[18,35],[18,41],[18,33],[18,7],[18,19],[18,12],[18,50],[18,21],[18,2],[18,34],[18,32],[18,25],[18,44],[31,17],[31,11],[31,41],[31,33],[31,7],[31,19],[31,12],[31,50],[31,5],[31,49],[31,21],[31,2],[31,32],[31,25],[31,36],[22,17],[22,35],[22,11],[22,41],[22,19],[22,12],[22,50],[22,2],[22,34],[22,25],[22,36],[22,44],[17,35],[17,11],[17,41],[17,33],[17,7],[17,24],[17,12],[17,50],[17,5],[17,49],[17,21],[17,2],[17,34],[17,32],[17,36],[17,44],[35,11],[35,41],[35,33],[35,24],[35,50],[35,5],[35,49],[35,21],[35,34],[35,32],[35,25],[35,44],[11,33],[11,19],[11,24],[11,12],[11,50],[11,5],[11,49],[11,21],[11,2],[11,34],[11,32],[11,36],[11,44],[41,7],[41,24],[41,12],[41,50],[41,5],[41,49],[41,21],[41,34],[41,32],[41,25],[41,36],[41,44],[33,7],[33,24],[33,12],[33,50],[33,49],[33,2],[33,34],[33,32],[33,25],[33,36],[33,44],[7,46],[7,19],[7,24],[7,49],[7,21],[7,34],[7,25],[46,24],[46,50],[46,49],[46,34],[46,25],[46,36],[19,24],[19,12],[19,5],[19,49],[19,21],[19,34],[19,32],[19,25],[19,36],[19,44],[24,12],[24,50],[24,5],[24,2],[24,34],[24,25],[24,36],[24,44],[12,50],[12,5],[12,2],[12,34],[12,32],[12,25],[12,36],[50,5],[50,49],[50,34],[50,32],[50,25],[50,36],[50,44],[5,49],[5,34],[5,25],[5,36],[5,44],[49,2],[49,34],[49,36],[49,44],[21,34],[21,36],[21,44],[2,34],[2,32],[2,36],[2,44],[34,32],[34,25],[34,36],[32,36],[36,44]]*/