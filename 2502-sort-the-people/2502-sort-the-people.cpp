class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<int> indices;
        for (int i = 0; i < names.size(); i++) {
            indices.push_back(i);
        }
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return heights[a] > heights[b];
        });
        vector<string> ans;
        for (int i = 0; i < indices.size(); i++) {
            ans.push_back(names[indices[i]]);
        }
        return ans;
    }
};

// My Code
// class Solution {
// public:
//     vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
//         unordered_map<int, string> list;
//         for(int i=0; i<size(names); i++){
//             list[heights[i]] = names[i];
//         }
//         sort(heights.begin(), heights.end(), greater<int>());
//         vector<string> res;
//         for(int a: heights){
//             res.push_back(list[a]);
//         }
//         return res;
//     }
// };