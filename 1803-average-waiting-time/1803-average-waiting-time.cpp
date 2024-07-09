class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int time = 0;
        unsigned long long int total_sum = 0;
        for(int i=0; i<customers.size(); i++){
            if (time < customers[i][0]) time = customers[i][0];
            time += customers[i][1];
            total_sum += time - customers[i][0];
        }
        double ans = static_cast<double>(total_sum) / customers.size();
        return ans;
    }
};