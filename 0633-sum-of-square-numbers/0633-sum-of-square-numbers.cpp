class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c==0 || c==1 || c==2) return true;
        vector<unsigned long long int> square;
        for(long long int i=0; i<c; i++){
            unsigned long long int a = i*i;
            if(a <= c) square.push_back(a);
            else break;
        }
        int i=0, j=square.size()-1;
        while(i<=j){
            unsigned long long int a = square[i] + square[j];
            if(a==c) return true;
            else if(a<c) i++;
            else if(a>c) j--;
        }
        return false;
    }
};