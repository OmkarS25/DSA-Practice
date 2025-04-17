// Using biset array
class Solution {
public:
    static int countPairs(vector<int>& nums, int k) {
        const int n=nums.size();
        bitset<128> freq[101];// instead of array vector<char>
        int cnt=0;
        for (int j=0; j<n; j++) {
            const int x=nums[j];
            // Cast to uint64_t* to access uint64 array B[2]
            uint64_t* B=(uint64_t*)(&freq[x]);

            for (int w=0; w<2; w++) { //128 bits in 2 words
                for (auto word=B[w]; word>0; word &= word-1) {
                    const int i=__builtin_ctzll(word)+w*64;
                    if ((i*j)%k==0) cnt++;
                }
            }
            freq[x][j]=1;
        }
        return cnt;
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
//     static int countPairs(vector<int>& nums, int k) {
//         const int n=nums.size();
//         vector<char> freq[101];
//         for(int i=0; i<n; i++){
//             int x=nums[i];
//             freq[x].push_back(i);
//         }
//         int cnt=0;
//         for( auto& fs: freq){
//             if (fs.size()<2) continue;
//             int fz=fs.size();
//             for(int i=0; i<fz-1; i++)
//                 for(int j=i+1; j<fz; j++)
//                     cnt+=(fs[i]*fs[j]%k==0);
//         }
//         return cnt;
//     }
// };