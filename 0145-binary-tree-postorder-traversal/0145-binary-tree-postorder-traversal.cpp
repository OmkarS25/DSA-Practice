class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) return ans;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        TreeNode* prev = nullptr;
        while(curr!=nullptr || !st.empty()){
            
            while(curr != nullptr){
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
                
            // If the current node has a right child and it is not processed yet
            if(curr->right != nullptr && curr->right != prev) {
                curr = curr->right; // Move to the right subtree
            } else {
                // If the current node's right subtree is already processed or absent
                st.pop();
                ans.push_back(curr->val);
                prev = curr; // Update prev to the current node
                curr = nullptr; // Set curr to nullptr to prevent further traversal
            }
        }
        return ans;
    }
};