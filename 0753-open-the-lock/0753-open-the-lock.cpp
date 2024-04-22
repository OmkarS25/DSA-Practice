class Solution {
public:
    static int openLock(vector<string>& deadends, const string& target) {
        bitset<10000> seen=0;// 0000~9999
        for(string& s: deadends){
            seen[stoi(s)]=1;
        }
        if (seen[0]) return -1;//edge case
        queue<pair<short, short>> q;
        q.emplace(0, 0);
        seen[0]=1;
        short z=stoi(target);
        short dec[4]={1, 10, 100,1000};
        while(!q.empty()){
            auto [turn, s]=q.front(); q.pop();
        //    cout<<turn<<":"<<s<<endl;
            if (s==z) return turn;
            short digit, t=s;
            for(short d=0; d<4; d++){// 8 ways of turning
                digit=t%10, t/=10;
                for(short i: {-1, 1}){
                    short dnext=(digit+i+10)%10;
                    short x=s+(dnext-digit)*dec[d];
                    if (!seen[x]) {
                        q.emplace(turn+1, x);
                        seen[x]=1;
                    }
                }
            }
        }
        return -1;
    }
};


/*NOTES
Approach
-Turn string to int. There are 0000~9999, 10000 states in total.
-Set a boolean array for the states seen before.
-Every combination in deadends is set to seen.
-Create a queue q for the pair (turn, state)
-Proceed the BFS using a while-loop; Each state of the 4 wheels has at most 8 ways for next turning; push the next state to q & mark it as seen.

How to optimize?
-C/C++ programmers persuit the performance.
-The 1st C++ codes has too many times using stoi for conversion from string to int; it is costly.
-Only the strings in deadends & target need to convert. The rest of computation uses just numerical operations. that saves time.
-There are totally 10000 combinations, a 16-bit integer type is enough, using short. bitset is really bitset in contrary to the boolean array which needs 1 byte for each element. Less memory is used. 
*/


// class Solution {
// public:
//     int openLock(vector<string>& deadends, const string& target) {
//         bool seen[10000]={0};// 0000~9999
//         for(string& s: deadends){
//             seen[stoi(s)]=1;
//         }
//         if (seen[0]) return -1;//edge case
//         queue<pair<int,string>> q;
//         q.emplace(0, "0000");
//         seen[0]=1;
//         while(!q.empty()){
//             auto [turn, s]=q.front(); q.pop();
//         //    cout<<turn<<":"<<s<<endl;
//             if (s==target) return turn;
//             for(int d=0; d<4; d++){// 8 ways of turning
//                 for(int i=-1; i<=1; i+=2){
//                     string t=s;
//                     char& move=t[d];
//                     move=(move-'0'+i+10)%10+'0';
//                     int x=stoi(t);
//                     if (!seen[x]) {
//                         q.emplace(turn+1, t);
//                         seen[x]=1;
//                     }
//                 }
//             }
//         }
//         return -1;
//     }
// };