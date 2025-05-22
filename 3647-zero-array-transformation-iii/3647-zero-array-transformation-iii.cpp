class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1]; // Descending order for second element
            else return a[0] < b[0]; // Ascending order for first element
        });

        priority_queue<int> available;
        int count = 0, n = nums.size(), index = 0;
        vector<int> freq(n+1, 0);

        for(int i=0; i<n; i++){
            count += freq[i];

            while(index<queries.size() && queries[index][0]<=i){
                available.push(queries[index++][1]);
            }

            while(count<nums[i] && !available.empty() && available.top()>=i){
                freq[available.top()+1]--;
                available.pop();
                count++;
            }
            
            if(count<nums[i]) return -1;
        }

        return available.size();
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();