class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, vector<int>> list;
        vector<int> res;
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
        for(const auto& a: list){
            if(a.second[0] && a.second[1]){
                res.push_back(a.first);
            }
        }
        return res;
    }
};