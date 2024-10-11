#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("-ffloat-store")
#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        // Add original indices to the times array
        for (int i = 0; i < n; ++i) {
            times[i].push_back(i);  // times[i][2] will store the friend's index
        }
        
        // Sort based on arrival times
        sort(times.begin(), times.end());
        
        // Min-heap to track available chairs
        priority_queue<int, vector<int>, greater<int>> availableChairs;
        for (int i = 0; i < n; ++i) {
            availableChairs.push(i);  // Initially, all chairs (0, 1, 2, ...) are available
        }
        
        // Min-heap to track chairs that are currently occupied (sorted by leave times)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occupiedChairs;
        
        for (int i = 0; i < n; ++i) {
            int arrival = times[i][0];
            int leave = times[i][1];
            int friendIndex = times[i][2];
            
            // Free up chairs that are no longer occupied before the current friend's arrival
            while (!occupiedChairs.empty() && occupiedChairs.top().first <= arrival) {
                availableChairs.push(occupiedChairs.top().second);
                occupiedChairs.pop();
            }
            
            // Assign the smallest available chair
            int assignedChair = availableChairs.top();
            availableChairs.pop();
            
            // If this is the target friend, return the assigned chair
            if (friendIndex == targetFriend) {
                return assignedChair;
            }
            
            // Mark the chair as occupied until the leave time
            occupiedChairs.push({leave, assignedChair});
        }
        
        return -1;  // This should never be reached
    }
};
