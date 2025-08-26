class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        float ans = INT_MIN, maxarea = INT_MIN;
        for(vector<int>& v : dimensions){
            float tmp = sqrt(v[0]*v[0] + v[1]*v[1]);
            float area = v[0]*v[1];
            if(ans < tmp){
                ans = tmp;
                maxarea = area; 
            }
            else if(ans == tmp && area > maxarea){
                maxarea = area;
            }
        }
        return maxarea;
    }
};