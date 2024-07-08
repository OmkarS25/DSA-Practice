class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> circle;
        for(int i=1; i<=n; i++){
            circle.push_back(i);
        }
        int curr_ind = 0;
        while(circle.size() > 1){
            int next_to_remove = (curr_ind + k-1) % circle.size();
            circle.erase(circle.begin() + next_to_remove);
            curr_ind = next_to_remove;
        }
        return circle[0];
    }
};