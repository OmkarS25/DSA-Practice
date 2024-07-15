/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution{
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodeMap;
        unordered_set<int> children;

        for(vector<int> & desc : descriptions){
            int parentVal = desc[0], childVal = desc[1], isLeft = desc[2];

            // Get or create the parent node
            if(nodeMap.find(parentVal) == nodeMap.end()){
                nodeMap[parentVal] = new TreeNode(parentVal);
            }
            TreeNode* parent = nodeMap[parentVal];

            // Get or create the child node
            if(nodeMap.find(childVal) == nodeMap.end()){
                nodeMap[childVal] = new TreeNode(childVal);
            }
            TreeNode* child = nodeMap[childVal];

            // Link the child to the parent
            if(isLeft) parent->left = child;
            else parent->right = child;

            // Marking this node as a child
            children.insert(childVal);
        }

        // The root will be the only node that is not a child
        TreeNode* root = nullptr;
        for(vector<int>& desc : descriptions){
            if(children.find(desc[0]) == children.end()){
                root = nodeMap[desc[0]];
                break;
            }
        }
        return root;
    }
};


// class Solution {
// public:
//     TreeNode* helper(TreeNode* head, int parent){
//         if(!head) return NULL;
//         if(head->val == parent) return head;
//         TreeNode* left = helper(head->left, parent);
//         TreeNode* right = helper(head->right, parent);
//         return left!=NULL ? left : right;
//     }
//     TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
//         TreeNode* dummyhead = new TreeNode();
//         for(vector<int> a: descriptions){
//             int parent = a[0], child = a[1], isLeft = a[2];
//             TreeNode* parent_p = helper(dummyhead, parent);
//             if(!parent_p) parent_p = new TreeNode(parent);
//             TreeNode* child_p = new TreeNode(child);
//             if(isLeft) parent_p->left = child_p;
//             else parent_p->right = child_p;
//             if(!dummyhead->left) dummyhead = parent_p;
//         }
//         return dummyhead->left;
//     }
// };