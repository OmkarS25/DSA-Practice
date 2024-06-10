class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> freqlist;
        for(int a : arr1){
            freqlist[a]++;
        }
        int index=0;
        for(int a : arr2){
            while(freqlist[a]){
                arr1[index++] = a;
                freqlist[a]--;
            }
        }
        int s = index;
        for(auto i=freqlist.begin(); i != freqlist.end(); i++){
            if(i->second > 0){
                while(i->second){
                    arr1[index++] = i->first;
                    i->second--;
                }
            }
        }
        sort(arr1.begin()+s, arr1.end());
        return arr1;
    }
};