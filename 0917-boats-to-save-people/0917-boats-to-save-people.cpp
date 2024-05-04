#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        //Using optimization for compiling
        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        // Use the comment below to instead of sort funtion for better performance.
        sort(people.begin(),people.end());
        int count = 0;
        for(int l=0, r=people.size()-1;l<=r; r--){
            count++;
            if (people[l]+people[r]<=limit)
                l++;          
        } 
        return count;
    }
};

//Use for optimization
// unsigned freq[30001]={0};
// int maxW=0, minW=30001;
// for(int x: people){
//     freq[x]++;
//     maxW=max(maxW, x);
//     minW=min(minW, x);
// }
// for (int i=minW, j=0; i<=maxW; i++){
//     int f=freq[i];
//     fill(people.begin()+j, people.begin()+j+f, i);
//     j+=f;
// }
//using while loop insead of for loop
// int left = 0, right = people.size() - 1;
// int count =0;
// while (left <= right) {
//     if (people[left] + people[right] <= limit) {
//         left++;
//     }
//     right--;
//     count++;
// }