class TrieNode {
public:
    string name;
    unordered_map<string, TrieNode*> children;
    bool marked = false;

    TrieNode(string name = "") : name(name) {}
};

class Solution {
    unordered_map<string, vector<TrieNode*>> serialMap;

    // Post-order serialize each subtree
    string serialize(TrieNode* node) {
        if (node->children.empty()) return "()";

        vector<pair<string, string>> serials;
        for (auto& [name, child] : node->children) {
            serials.push_back({name, serialize(child)});
        }

        // Sort to ensure uniqueness of structure
        sort(serials.begin(), serials.end());

        string serial;
        for (auto& [name, sub] : serials) {
            serial += name + sub;
        }

        serial = "(" + serial + ")";

        serialMap[serial].push_back(node);
        return serial;
    }

    void collectPaths(TrieNode* node, vector<string>& path, vector<vector<string>>& res) {
        if (node->marked) return;

        if (!node->name.empty()) path.push_back(node->name);
        if (!node->name.empty()) res.push_back(path);

        for (auto& [_, child] : node->children) {
            collectPaths(child, path, res);
        }

        if (!node->name.empty()) path.pop_back();
    }

public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        TrieNode* root = new TrieNode();

        // Step 1: Build Trie
        for (auto& path : paths) {
            TrieNode* node = root;
            for (const string& folder : path) {
                if (!node->children.count(folder)) {
                    node->children[folder] = new TrieNode(folder);
                }
                node = node->children[folder];
            }
        }

        // Step 2: Serialize subtrees and detect duplicates
        serialize(root);

        // Step 3: Mark duplicate nodes
        for (auto& [_, nodes] : serialMap) {
            if (nodes.size() > 1) {
                for (auto* node : nodes) {
                    node->marked = true;
                }
            }
        }

        // Step 4: Collect non-duplicate paths
        vector<vector<string>> res;
        vector<string> currentPath;
        for (auto& [_, child] : root->children) {
            collectPaths(child, currentPath, res);
        }

        return res;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();