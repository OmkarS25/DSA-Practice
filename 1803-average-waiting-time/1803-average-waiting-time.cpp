class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        int time = 0;
        // unsigned long long int total_sum = 0;
        double total_sum = 0;
        for(int i=0; i<customers.size(); i++){
            if (time < customers[i][0]) time = customers[i][0];
            time += customers[i][1];
            total_sum += time - customers[i][0];
        }
        // double ans = static_cast<double>(total_sum) / customers.size();
        // return ans;
        return total_sum / customers.size();
    }
};