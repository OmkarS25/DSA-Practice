class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(), capacity.end(), greater<int>());
        int totalApples = 0;
        for(int & i : apple) totalApples += i;
        int i = 0;
        while(i<capacity.size()){
            totalApples -= capacity[i++];
            if(totalApples <= 0) return i;
        }
        return i;
    }
};