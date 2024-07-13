class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<vector<int>> robots;
        for(int i = 0; i < n; ++i){
            robots.push_back({positions[i], healths[i], directions[i], i});
        }
        sort(robots.begin(), robots.end());
        vector<vector<int>> stack;
        for(auto& robot : robots){
            if(robot[2] == 'R' || stack.empty() || stack.back()[2] == 'L'){
                stack.push_back(robot);
                continue;
            }
            if(robot[2] == 'L'){
                bool add = true;
                while(!stack.empty() && stack.back()[2] == 'R' && add){
                    int last_health = stack.back()[1];
                    if(robot[1] > last_health){
                        stack.pop_back();
                        robot[1] -= 1;
                    } 
                    else if(robot[1] < last_health){
                        stack.back()[1] -= 1;
                        add = false;
                    } 
                    else{
                        stack.pop_back();
                        add = false;
                    }
                }
                if(add) stack.push_back(robot);
            }
        }
        vector<int> result;
        sort(stack.begin(), stack.end(), [](vector<int>& a, vector<int>& b) {return a[3] < b[3];});
        for(auto& robot : stack) {
            result.push_back(robot[1]);
        }
        return result;
    }
};

// class Solution {
// public:
//     vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
//         vector<pair<int, int>> robots;
//         for (int i = 0; i < positions.size(); ++i) {
//             robots.push_back({positions[i], i});
//         }
//         // Sort robots based on positions
//         sort(robots.begin(), robots.end());
//         stack<int> rightStack;
//         vector<int> survived(positions.size(), 1);
//         for (auto& [pos, idx] : robots) {
//             if (directions[idx] == 'R') {
//                 rightStack.push(idx);
//             } 
//             else {
//                 while (!rightStack.empty() && healths[rightStack.top()] < healths[idx]) {
//                     survived[rightStack.top()] = 0;
//                     rightStack.pop();
//                 }
//                 if (!rightStack.empty() && healths[rightStack.top()] == healths[idx]) {
//                     survived[rightStack.top()] = 0;
//                     survived[idx] = 0;
//                     rightStack.pop();
//                 } 
//                 else if (!rightStack.empty()) {
//                     survived[idx] = 0;
//                     healths[rightStack.top()] -= 1;
//                 }
//             }
//         }
//         vector<int> result;
//         for (int i = 0; i < survived.size(); ++i) {
//             if (survived[i]) {
//                 result.push_back(healths[i]);
//             }
//         }
//         return result;
//     }
// };