class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;
        map<int,int> mp;
        for(int a: hand){
            mp[a]++;
        }
        for(auto it : mp){
            if(mp[it.first] > 0){
                for(int i=1; i<groupSize; i++){
                    mp[it.first+i] -= mp[it.first];
                    if(mp[it.first+i] < 0) return false;
                }
            }
        }
        return true;
    }
};

// class Solution {
//     public boolean findsucessors(int[] hand, int groupSize, int i, int n) {
//         int f = hand[i] + 1;
//         hand[i] = -1;
//         int count = 1;
//         i++;
//         while (i < n && count < groupSize) {
//             if (hand[i] == f) {
//                 f = hand[i] + 1;
//                 hand[i] = -1;
//                 count++;
//             }
//             i++;
//         }
//         if (count != groupSize)
//             return false;
//         else
//             return true;
//     }
//     public boolean isNStraightHand(int[] hand, int groupSize) {
//         int n = hand.length;
//         if (n % groupSize != 0)
//             return false;
//         Arrays.sort(hand);
//         int i = 0;
//         for (; i < n; i++) {
//             if (hand[i] >= 0) {
//                 if (!findsucessors(hand, groupSize, i, n))
//                     return false;
//             }
//         }
//         return true;
//     }
// };