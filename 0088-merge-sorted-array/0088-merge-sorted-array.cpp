class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0, j=0;
        int *temp = new int[m+n];
        int z = 0;
        while(i<m && j<n){
            if(nums1[i] < nums2[j]){
                temp[z++] = nums1[i++];
            }
            else{
                temp[z++] = nums2[j++];
            }
        }
        while(i<m){
            temp[z++] = nums1[i++];
        }
        while(j<n){
            temp[z++] = nums2[j++];
        }
        for(int i=0; i<nums1.size(); i++){
            nums1[i] = temp[i];
        }
        delete[] temp;
    }
};