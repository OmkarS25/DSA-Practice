class Solution {
public:
    long long count(string word, int k) {
        unordered_map<char, int> mp;
        long long ans = 0;
        int j = 0, cnt = 0;
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' ||
                word[i] == 'o' || word[i] == 'u') {
                mp[word[i]]++;
            } else {
                cnt++;
            }
            while (j <= i && mp.size() >= 5 && cnt >= k) {
                if (word[j] == 'a' || word[j] == 'e' || word[j] == 'i' ||
                    word[j] == 'o' || word[j] == 'u') {
                    mp[word[j]]--;
                    if (mp[word[j]] == 0) {
                        mp.erase(word[j]);
                    }
                } else {
                    cnt--;
                }
                j++;
            }
            ans += (i-j + 1);
        }
        return ans;
    }
    long long countOfSubstrings(string word, int k) {
        return count(word,k+1)-count(word,k);
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();