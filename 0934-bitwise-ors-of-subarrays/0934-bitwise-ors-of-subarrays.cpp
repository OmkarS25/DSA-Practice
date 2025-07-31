class Solution {
public:
    int subarrayBitwiseORs(std::vector<int>& arr) {
        unordered_set<int> result_ors;
        unordered_set<int> current_ors;

        for (int x : arr) {
            unordered_set<int> next_ors;
            next_ors.insert(x);
            for (int y : current_ors) {
                next_ors.insert(x | y);
            }
            result_ors.insert(next_ors.begin(), next_ors.end());
            current_ors = next_ors;
        }

        return result_ors.size();
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();

// class Solution {
// public:
//     void helper(vector<int>& arr, const int& n, int index, int curr, 
//                 set<int>& unique, bool notincluded){
//         if(index >= n) return;
        
//         if(notincluded)
//             helper(arr, n, index+1, curr, unique, true);
        
//         curr = curr ^ arr[index];
//         unique.insert(curr);
        
//         helper(arr, n, index+1, curr, unique, false);
//     }
//     int subarrayBitwiseORs(vector<int>& arr) {
//         const int n = arr.size();
//         if(n == 1) return 1;

//         set<int> unique;
//         helper(arr, n, 0, 0, unique, true);

//         // Does the arr contains zero?
//         bool zero = false;
//         for(int a : arr){
//             if(0 == a){
//                 zero = true;
//                 break;
//             }
//         }
//         if(!zero) unique.erase(0);

//         // Testing print
//         for(int a : unique) cout<<a<<" ";
        
//         return unique.size();
//     }
// };