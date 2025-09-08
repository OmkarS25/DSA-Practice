class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        int maxi = INT_MIN, mini = INT_MAX;

        // process first k elements ko
        for(int i=0; i<nums.size(); i++) {  
            pq.push({nums[i][0], {i, 0}});
            maxi = max(maxi, nums[i][0]);
            mini = min(mini, nums[i][0]);
        }

        int ansStart = mini, ansEnd = maxi;

        while(!pq.empty()) {
            pair<int, pair<int,int>> topNode = pq.top();
            int topData = topNode.first;
            int topRow = topNode.second.first;
            int topCol = topNode.second.second;
            pq.pop();
            mini = topData;
            // compare krlete h for smaller range
            if((maxi - mini) < (ansEnd - ansStart)) {
                ansStart = mini;
                ansEnd = maxi;
            }
            // insertion wala step
            if(topCol + 1 < nums[topRow].size()) {
                int newElement = nums[topRow][topCol + 1];
                maxi = max(maxi, newElement);
                pq.push({newElement, {topRow, topCol + 1}});
            }
            else break;
        }
        return {ansStart, ansEnd};
    }
};