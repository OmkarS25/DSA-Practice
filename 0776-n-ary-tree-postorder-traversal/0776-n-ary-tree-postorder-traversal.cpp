/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

auto init = [](){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    void helper(Node* root, vector<int>& ans){
        if(!root) return;
        for(Node* a : root->children){
            helper(a, ans);
        }
        ans.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }

//     vector<int> postorder(Node* root) {
//         vector<int> ans;
//         if (!root) return ans;

//         stack<Node*> nodeStack;
//         stack<int> outputStack;
//         nodeStack.push(root);

//         while (!nodeStack.empty()) {
//             Node* node = nodeStack.top();
//             nodeStack.pop();
//             outputStack.push(node->val);

//             for (Node* child : node->children) {
//                 if (child) {
//                     nodeStack.push(child);
//                 }
//             }
//         }

//         while (!outputStack.empty()) {
//             ans.push_back(outputStack.top());
//             outputStack.pop();
//         }

//         return ans;
//     }
};