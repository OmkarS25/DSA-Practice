class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        unordered_set<int> setA, setB;
        int count = 0;
        for(int i = 0; i < A.size(); i++){
            if(setB.count(A[i])) count++;
            setA.insert(A[i]);
            if(setA.count(B[i])) count++;
            setB.insert(B[i]);
            ans.push_back(count);
        }
        return ans;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();