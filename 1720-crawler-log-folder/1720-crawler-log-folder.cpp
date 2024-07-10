class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count = 0;
        for(string &a : logs){
            if(a == "../"){
                if(count) count--;
            }
            else if(a == "./"){
                continue;
            }
            else{
                count++;
            }
        }
        return count;
    }
};