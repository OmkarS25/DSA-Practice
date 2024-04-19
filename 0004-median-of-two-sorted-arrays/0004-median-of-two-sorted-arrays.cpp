class Solution {
private:
    void merge(vector<int>&left, vector<int>&right, vector<int>&arr){
        int lenLeft = left.size();
        int lenRight = right.size();
        int leftIndex = 0, rightIndex = 0 ,mainArrayIndex = 0;
        while(leftIndex < lenLeft &&  rightIndex < lenRight) {
		
		if(left[leftIndex] < right[rightIndex] ) {
			arr[mainArrayIndex] =  left[leftIndex];
			mainArrayIndex++;
			leftIndex++;
		}
		else {
			arr[mainArrayIndex] =  right[rightIndex];
			mainArrayIndex++;
			rightIndex++;
		}
	    }
        while(rightIndex < lenRight) {
		arr[mainArrayIndex] =  right[rightIndex];
		mainArrayIndex++;
		rightIndex++;
        }
        while(leftIndex < lenLeft) {
            arr[mainArrayIndex] =  left[leftIndex];
            mainArrayIndex++;
            leftIndex++;
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans=0;
        vector<int> merged(nums1.size()+ nums2.size(),-1);
        merge(nums1, nums2, merged);
        int len = merged.size()-1;
        if (len%2 != 0) {
           ans = double (merged[(len/2)] + merged[(len/2)+1])/2;
        }
        else ans = merged[(len/2)];
        return ans;
    }
};