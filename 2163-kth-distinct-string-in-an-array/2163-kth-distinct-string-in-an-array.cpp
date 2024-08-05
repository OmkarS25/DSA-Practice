class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> list;
        for(string str: arr){
            list[str]++;
        }
        vector<string> temp;
        for(string str: arr){
            if(list.find(str)->second == 1){
                temp.push_back(str);
            }
        }
        int n = temp.size();
        if(n < k) return "";
        return temp[k-1];
    }
};