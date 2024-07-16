class Solution {
public:
    bool find (TreeNode* node, int val, string& path){
        if (node->val == val) return true;
        if (node->left && find(node->left, val, path)) path.push_back('L');
        else if (node->right && find(node->right, val, path)) path.push_back('R');
        return !path.empty();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string startPath, destPath;
        find(root, startValue, startPath);
        find(root, destValue, destPath);
        while (!startPath.empty() && !destPath.empty() && startPath.back() == destPath.back()){
            startPath.pop_back();
            destPath.pop_back();
        }
        return string(startPath.size(), 'U') + string(destPath.rbegin(), destPath.rend());
    }
};

// class Solution {
// public:
//     string getDirections(TreeNode* root, int startValue, int destValue) {
//         vector<string> path_to_start, path_to_destination;
//         find_path_from_root(root, startValue, path_to_start);
//         find_path_from_root(root, destValue, path_to_destination);
//         int common_path_len = 0;
//         while (common_path_len < path_to_start.size() && common_path_len < path_to_destination.size() &&
//                path_to_start[common_path_len] == path_to_destination[common_path_len]) {
//             common_path_len++;
//         }
//         vector<string> res(path_to_start.size() - common_path_len, "U");
//         res.insert(res.end(), path_to_destination.begin() + common_path_len, path_to_destination.end());
//         string result;
//         for (const auto& dir : res) {
//             result += dir;
//         }
//         return result;
//     }
//     bool find_path_from_root(TreeNode* cur_node, int target_value, vector<string>& path_to_append) {
//         if (!cur_node) return false;
//         if (cur_node->val == target_value) return true;
//         path_to_append.push_back("R");
//         if (find_path_from_root(cur_node->right, target_value, path_to_append)) return true;
//         path_to_append.pop_back();
//         path_to_append.push_back("L");
//         if (find_path_from_root(cur_node->left, target_value, path_to_append)) return true;
//         path_to_append.pop_back();
//         return false;
//     }
// };