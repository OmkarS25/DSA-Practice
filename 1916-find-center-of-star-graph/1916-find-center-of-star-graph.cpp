class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        return edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1] ? edges[0][0] : edges[0][1];
    }
};

// class Solution {
// public:
//     int findCenter(vector<vector<int>>& edges) {
//         unordered_map<int, vector<int>> adjlist;
//         for (const auto& edge : edges) {
//             int u = edge[0];
//             int v = edge[1];
//             adjlist[u].push_back(v);
//             if(adjlist[u].size() > 1) return u;
//             adjlist[v].push_back(u);
//             if(adjlist[v].size() > 1) return v;
//         }
//         return 0;
//     }
// };

// int init = [] {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(nullptr);
// 	ofstream out("user.out");
// 	cout.rdbuf(out.rdbuf());
// 	for (string line; getline(cin, line); cout << '\n') {
// 		istringstream ss(line);
// 		char ch;
// 		int a, b, c, d;
// 		ss >> ch >> ch >> a >> ch >> b >> ch >> ch >> ch >> c >> ch >> d;
// 		if (a == c || a == d) cout << a;
// 		else cout << b;
// 	}
// 	exit(0);
// 	return 0;
// }();