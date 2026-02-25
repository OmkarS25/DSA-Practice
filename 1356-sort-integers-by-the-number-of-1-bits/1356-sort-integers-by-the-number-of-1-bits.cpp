class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int& a, int& b){
            if(int(__builtin_popcount(a)) == int(__builtin_popcount(b)))
                return a < b;
            else return int(__builtin_popcount(a)) < int(__builtin_popcount(b));
        });
        return arr;
    }
};