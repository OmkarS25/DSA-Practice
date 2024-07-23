class Solution {
public:
    static bool customcomp(int a, int b, const unordered_map<int, int>& list){
        if (list.at(a) != list.at(b)) {
            return list.at(a) < list.at(b);
        }
        return a > b; 
    }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> list;
        for(int a: nums){
            list[a]++;
        }
        sort(nums.begin(), nums.end(), [&list] (int a, int b){
            // return customcomp(a, b, list);
            if(list[a] != list[b]){
                return list[a] < list[b];
            }
            return a > b;
        });
        return nums;
    }
};