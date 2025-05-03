class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n[6]={0};
        for(int i=0;i<tops.size();i++){
             //count the integer that occurs both in top[i] and bottoms[i] only once!
            if(tops[i]==bottoms[i]) n[tops[i]-1]++;
            else 
            {
               n[tops[i]-1]++;
               n[bottoms[i]-1]++;
            } 
        }
        int nn=bottoms.size();
        int ti=0; int bi=0; // count occurences of that number in top and bottom rows
        int mino=INT_MAX;
        for(int i=0;i<6;i++){
               if(n[i]==nn){
                ti=0; bi=0;
                 
                 for(int j=0;j<nn;j++){
                     if(tops[j]==i+1) ti++;
                     if(bottoms[j]==i+1) bi++;
                 }
                 mino=min(nn-max(ti,bi),mino);// min swap logic
               }
        }
        if(mino!=INT_MAX) return mino;
        return -1;

    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();