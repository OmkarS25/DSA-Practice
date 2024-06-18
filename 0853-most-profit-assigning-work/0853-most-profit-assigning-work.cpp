class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int totalProfit = 0;
        vector<pair<int, int>> jobs;

        for (int i = 0; i < profit.size(); i++) {
            jobs.emplace_back(difficulty[i], profit[i]);
        }
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());

        int maxProfitSoFar = 0;
        int jobIndex = 0;
        
        for (int w : worker) {
            // For the current worker ability, finding the most profitable job they can do
            while (jobIndex < jobs.size() && jobs[jobIndex].first <= w) {
                maxProfitSoFar = max(maxProfitSoFar, jobs[jobIndex].second);
                jobIndex++;
            }
            totalProfit += maxProfitSoFar;
        }
        return totalProfit;
    }
};