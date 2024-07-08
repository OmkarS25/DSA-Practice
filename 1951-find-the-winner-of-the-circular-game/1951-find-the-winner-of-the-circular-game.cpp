class Solution {
public:
    // Bottom-up DP with constant space
    int findTheWinner(int n, int k) {
        int res = 0;
        for (int player_num = 2; player_num <= n; ++player_num) {
            res = (res + k) % player_num;
        }
        return res + 1;
    }

    // Recursion With Subproblems
    // int recursion(int n, int k) {
    //     if (n == 1) {
    //         return 0;
    //     }
    //     return (recursion(n - 1, k) + k) % n;
    // }
    // int findTheWinner(int n, int k) {
    //     return recursion(n, k) + 1;
    // }

    // Simulation
    // int findTheWinner(int n, int k) {
    //     vector<int> circle;
    //     for(int i=1; i<=n; i++){
    //         circle.push_back(i);
    //     }
    //     int curr_ind = 0;
    //     while(circle.size() > 1){
    //         int next_to_remove = (curr_ind + k-1) % circle.size();
    //         circle.erase(circle.begin() + next_to_remove);
    //         curr_ind = next_to_remove;
    //     }
    //     return circle[0];
    // }
};