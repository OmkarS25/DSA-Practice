class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(string & str: details){
            string num;
            num += str[11];
            num += str[12];
            int age = stoi(num);
            // if(str[11] >= '6') {
            //     if(str[12] > '0') count++;
            // }
            if(age > 60) count++;
        }
        return count;
    }
};