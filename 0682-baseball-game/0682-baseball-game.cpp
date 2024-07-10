class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> eq;
        for(string &a : operations){
            if(a == "C"){
                eq.pop();
            }
            else if(a == "D"){
                eq.push(eq.top()*2);
            }
            else if(a == "+"){
                int temp_1 = eq.top();
                eq.pop();
                int temp_2 = eq.top();
                eq.push(temp_1);
                eq.push(temp_1 + temp_2);
            }
            else{
                eq.push(stoi(a));
            }
        }
        int ans = 0;
        while(!eq.empty()){
            ans += eq.top();
            eq.pop();
        }
        return ans;
    }
};