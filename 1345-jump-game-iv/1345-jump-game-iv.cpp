class Solution {
public:
    int minJumps(vector<int>& arr) {
        int size = arr.size();
        if(size == 1) return 0;
        unordered_map<int,vector<int>>mp ; // value,index;

        for(int i = 0;i<size;i++){
            mp[arr[i]].push_back(i);
        }

        queue<pair<int,int>>q; // idx , level
        q.push({0,0});

        vector<int>vis(size,0) ; // index vis or not
        vis[0] = 1;

        while(!q.empty()){
            int idx = q.front().first;
            int level = q.front().second;
            q.pop();

            if(idx+1 <size && vis[idx+1] == 0){
                q.push({idx+1,level+1});
                vis[idx+1] = 1;
                if(idx+1 == size-1) return level+1;
            }
            if(idx-1 >= 0 && vis[idx-1] == 0){
                q.push({idx-1,level+1});
                vis[idx-1] = 1;
            }
            int a = arr[idx];
            int n = mp[arr[idx]].size();

            for(int i = 0; i < n; i++) {
                int nextIdx = mp[a][i];
                if(!vis[nextIdx]) {

                    vis[nextIdx] = 1;
                    q.push({nextIdx, level + 1});

                    if(nextIdx == size - 1) return level + 1;
                }
            }
            mp[arr[idx]].clear();
        }

       return size-1;
    }
};