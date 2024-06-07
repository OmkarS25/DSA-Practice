class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans = "";
        string temp = "";
        sentence += " ";
        for(char a : sentence){
            if(a == ' '){
                // searching through the words
                for(string &word : dictionary){
                    if(word.length() < temp.length()){
                        bool change = true;
                        // if any char does not match with temp then stop.
                        for(int i=0; i<word.length(); i++){
                            if(word[i] != temp[i]){
                                change = false;
                                break;
                            }
                        }
                        // if change possilbe then replace the word
                        if(change){
                            temp = word;
                        }
                    }
                }
                // saving the ans
                ans += temp;
                ans += " ";
                temp = "";
            }
            else temp += a;
        }
        ans.pop_back();
        return ans;
    }
};

// dictonary ke word ki len sentence ke word se choti hi hogi bcz agar dictonary ka pura word comapare hota hai toh hi woh replace hoga.
// dictonary ke saare words ke compare hone dene ka break nahi karna warna smallest wala nahi milega.
// 