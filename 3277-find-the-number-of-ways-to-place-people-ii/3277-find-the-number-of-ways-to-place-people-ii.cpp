class Solution {
public:
    int numberOfPairs(vector<vector<int>>& p) {
        const int n = p.size();
        sort(p.begin(),p.end(),[](const vector<int>& a, const vector<int>& b){
            return a[0]==b[0] ? a[1] > b[1] : a[0] < b[0]; 
        });
        int ans = 0;
        for(int i=0; i<n; i++){
            int last = INT_MIN, x1 = p[i][0], y1 = p[i][1];
            for(int j=i+1; j<n; j++){
                int x2 = p[j][0], y2 = p[j][1];
                if(y2<=y1 && y2>last) ans++, last = y2;
            }
        }
        return ans;
    }
};