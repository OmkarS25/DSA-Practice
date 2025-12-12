class Solution {
public:
    vector<string> split(string& str, char delimiter){
        stringstream ss(str);
        vector<string> res;
        string token;
        while (getline(ss, token, delimiter))
            res.push_back(token);
        return res;
    }

    int GetID(string& s){ return stoi(s.substr(2)); }

    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(),events.end(),[&](vector<string>&a , vector<string>&b){
            int timeA = stoi(a[1]), timeB = stoi(b[1]);
            return (timeA == timeB) ? a[0] > b[0] : timeA < timeB;
        });

        vector<int> ans(numberOfUsers,0), time(numberOfUsers,0);
        for(auto event : events){
            if(event[0] == "MESSAGE"){
                if(event[2] == "ALL"){
                    for(auto &i : ans) i++;
                }
                else if(event[2] == "HERE"){
                    for(int i=0;i<numberOfUsers; i++)
                        if(stoi(event[1]) >= time[i]) ans[i]++;
                }
                else{
                    vector<string>ids = split(event[2],' ');
                    for(auto id : ids){
                        int num = GetID(id);
                        ans[num]++;
                    }
                }
            }
            else time[stoi(event[2])] = (stoi(event[1]) + 60);
        }
        return ans;
    }
};