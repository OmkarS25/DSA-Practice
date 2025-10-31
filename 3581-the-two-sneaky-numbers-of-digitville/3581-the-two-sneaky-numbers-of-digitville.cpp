class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int arr[101] = {0};
        for(int i : nums){
            arr[i]++;
        }
        vector<int> ans;
        for(int i=0; i<101; i++){
            if(arr[i] == 2) ans.push_back(i);
        }
        return ans;
    }
};