class Solution {
public:
    int myAtoi(string s) {
        if(s.length() == 0) return 0;
        int num=0;
        try{
        num = stoi(s);
        } catch (const out_of_range&){
            for(char a:s){
                if(a=='-') return INT_MIN;
            }
            return INT_MAX;
        } catch (const invalid_argument&){
            return 0;
        }
        return num;
    }
};


//testcases
// 2^31 = 2,14,74,83,648;
//"1123 21 5"
//"-1123u3761867"
//"00000-42a1234"
//"-000000000000000000000000000001"
//"-91283472332"
//"-115579378e25"