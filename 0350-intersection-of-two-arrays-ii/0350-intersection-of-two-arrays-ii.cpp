class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
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
            int n1=a.second[0], n2=a.second[1];
            while(n1 && n2){
                n1--, n2--;
                res.push_back(a.first);
            }
        }
        return res;
    }
};