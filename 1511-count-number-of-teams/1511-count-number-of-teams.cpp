class Solution {
public:
    int numTeams(vector<int>& rating) {
        const int n = rating.size();
        int cnt = 0;
        for(int i=1; i<n-1; i++){
            int L[2]={0}, R[2]={0};
            for(int j=0; j<i; j++) // Count ratings on the left of i
                L[rating[j] < rating[i]]++; // rating is unique
            for (int k=i+1; k<n; k++) // Count ratings on the right of i 
                R[rating[k] < rating[i]]++;
            cnt += L[0]*R[1] + L[1]*R[0]; // number of valid teams
        }
        return cnt;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();