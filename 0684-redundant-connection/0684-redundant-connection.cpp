class disJoint_Set{
public:
    vector<int>parent;
    vector<int>size;
    disJoint_Set(int n){
        parent.resize(n+1, 0);
        size.resize(n+1, 1);
        for(int i = 0;i <= n;i++){
            parent[i] = i;
        }
    }

    int findParent(int node){
        if(node == this->parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }

    void checkConnection(int node1, int node2){
        int up_node1 = this->findParent(node1);
        int up_node2 = this->findParent(node2);

        if(up_node1 == up_node2) return;

        if(size[up_node1] <= size[up_node2]){
            parent[up_node1] = up_node2;
            size[up_node2] += size[up_node1];
        }
        else{
            parent[up_node2] = up_node1;
            size[up_node1] += size[up_node2];
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        disJoint_Set* obj = new disJoint_Set(n);

        vector<int>ans;
        for(auto it : edges){
            int from = it[0];
            int to = it[1];

            int up_from = obj->findParent(from);
            int up_to = obj->findParent(to);
            if(up_from == up_to){
                ans.push_back(from);
                ans.push_back(to);
            }
            else{
                obj->checkConnection(from, to);
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