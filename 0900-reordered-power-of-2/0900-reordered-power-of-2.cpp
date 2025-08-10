#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = sortDigits(n);

        for(int i = 0; i<31; i++){
            int power = 1 << i;
            if(s == sortDigits(power))
                return true;
        }
        return false;
    }

    string sortDigits(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        return s;
    }
};

// class Solution {
//     void permute(string str, int l, int r, bool& ans) {
//         if (l == r){
//             if(str[0] != '0'){
//                 long long n = stoll(str);
//                 bitset<64> bin(n);
//                 auto count = bin.count();
//                 if(count == 1) ans = true;
//             }
//         }
//         else{ 
//             // Permutations made 
//             for (int i = l; i <= r; i++) { 
//                 // Swapping done 
//                 swap(str[l], str[i]); 

//                 // Recursion called 
//                 permute(str, l+1, r, ans); 

//                 //backtrack 
//                 swap(str[l], str[i]); 
//             } 
//         } 
//     } 
// public:
//     bool reorderedPowerOf2(int n) {
//         if(n == 1) return true;
//         bool ans = false;
//         string tmp = to_string(n);
//         permute(tmp, 0, tmp.size()-1, ans);
//         return ans;
//     }
// };