class Solution {
public:
    int maxDistance(string s, int k) {
        // Step 1: start at origin
        int x = 0, y = 0;  
        
        // Track the maximum distance
        int ans = 0;
        
        // Step 2: go through each move
        for (int i = 0; i < s.size(); ++i){  
            char c = s[i];
        
            if (c == 'N') y++;     
            else if (c == 'S') y--;
            else if (c == 'E') x++;
            else if (c == 'W') x--;

            // Step 3: Calculate potential max distance with up to k changes
            int real_dist = abs(x) + abs(y);
            int dist = min(real_dist + 2 * k, i + 1);

            // Step 4: Update max distance found so far
            ans = max(ans, dist);
        }

        // Step 5: Return the result
        return ans;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();