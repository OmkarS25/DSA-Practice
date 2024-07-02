class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, vector<int>> list;
        vector<vector<int>> res;
        for(int a: nums1){
            list[a].push_back(0);
            list[a].push_back(0);
            list[a][0]++;
        }
        for(int a: nums2){
            list[a].push_back(0);
            list[a].push_back(0);
            list[a][1]++;
        }
        vector<int> res0, res1;
        for(const auto& a: list){
            int n1=a.second[0], n2=a.second[1];
            if(n1 > 0 && n2 == 0){
                res0.push_back(a.first);
            }
            else if(n1 == 0 && n2 > 0){
                res1.push_back(a.first);
            }
        }
        res.push_back(res0);
        res.push_back(res1);
        return res;
    }
};