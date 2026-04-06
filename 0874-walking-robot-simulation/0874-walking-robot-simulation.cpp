static const auto init = [](){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
private:
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  // N, E, S, W
    int dirIndex = 0;  
    void turnLeft() { dirIndex = (dirIndex + 3) % 4; }
    void turnRight() { dirIndex = (dirIndex + 1) % 4; }

public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> obstacleSet;
        for (auto& obstacle : obstacles) { 
            obstacleSet.insert(to_string(obstacle[0]) + "," + to_string(obstacle[1])); 
        }
        int x = 0, y = 0, maxDist = 0;
        for (int command : commands) {
            if (command == -2) turnLeft();
            else if (command == -1) turnRight();
            else {
                for (int i = 0; i < command; i++) {
                    int newX = x + directions[dirIndex].first, newY = y + directions[dirIndex].second;
                    string newPos = to_string(newX) + "," + to_string(newY);
                    if (obstacleSet.find(newPos) != obstacleSet.end()) break;
                    x = newX;
                    y = newY;
                    maxDist = max(maxDist, x * x + y * y);
                }
            }
        }
        return maxDist;
    }
};
