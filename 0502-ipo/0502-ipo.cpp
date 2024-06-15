class Solution {
public:
    int findMaximizedCapital(int k, int balance, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> projects;
        for (int i = 0; i < profits.size(); i++) {
            projects.emplace_back(capital[i], profits[i]);
        }
        sort(projects.begin(), projects.end());
        priority_queue<int> availableProjects;
        int index = 0;
        for (int i = 0; i < k; i++) {
            while (index < projects.size() && projects[index].first <= balance) {
                availableProjects.push(projects[index].second);
                index++;
            }
            if (availableProjects.empty()) break;
            balance += availableProjects.top();
            availableProjects.pop();
        }
        return balance;
    }
};