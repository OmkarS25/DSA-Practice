class Solution {
public:
    bool isPrime(int x) { 
        if (x < 2) return false; 
        if (x % 2 == 0) return x == 2; 
        for (int i = 3; i * i <= x; i += 2) { 
            if (x % i == 0) return false; 
        } 
        return true; 
    }
    int helper(int n){
        int res = 0;
        // Check if n is a perfect cube and its cube root is prime → return 1 + p + p² + p³.
        int root = round(cbrt(n)); 
        if (root * root * root == n && isPrime(root)) { 
            return 1 + root + root * root + n; 
        }

        // Otherwise, try dividing n by integers up to √n.
        // If you find a factorization n = p × q with both p and q primes (and distinct), return 1 + p + q + n.
        // Else return 0.

        for (int i = 2; i * i <= n; i++) { 
            if (n % i == 0) { 
                int j = n / i; 
                if (i != j && isPrime(i) && isPrime(j)) { 
                    return 1 + i + j + n;
                } 
                return 0; 
            } 
        } 
        return 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(int n: nums){
            ans += helper(n);
        }
        return ans;
    }
};