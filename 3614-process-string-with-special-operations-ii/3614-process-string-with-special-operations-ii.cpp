class Solution {
public:
    char processStr(string s, long long k) {
        long long ans = 0;

        // Part-1: Forward Pass (Calculate Total Length)
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '*') ans = (ans==0) ? ans : ans-1;
            else if(s[i] == '#') ans *= 2;
            else if(s[i] == '%') ans = ans;
            else ans++;
        }

        // Part-2: Base Case Check
        if (k>=ans) return '.';

        // Part-3: Backward Pass
        for(int i=s.length()-1; i>=0; i--){
            char ch = s[i];

            if(ch == '*') ans++; // Since it popped an element going forward, we add 1 to ans to revert the size.
            
            else if(ch == '#'){ // The size halves. If k is in the second half (k >= mid), we subtract mid from k to wrap it back into the first half.
                long long mid = ans/2;
                k = (k<mid) ? k : k-mid;
                ans/=2;
            }
            
            else if(ch == '%'){ // The size remains the same, but we must update k using the symmetry formula (explained below).
                long long mid = ans/2;
                k = 2*mid - k;
                if(ans%2==0) k--;
            }
            
            else{ // We reduce the ans by 1. At this exact moment, if our unwound string size matches k (ans == k), we have found our answer!
                ans--;
                if(ans == k) return ch;
            }
        }
        return '.';
    }
};