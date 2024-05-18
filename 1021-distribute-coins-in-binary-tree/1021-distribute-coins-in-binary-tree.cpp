class Solution {
public:
    int countMoves(TreeNode* &root, int &moves){
        if(!root) return 0;
        int balance = countMoves(root->left, moves) + countMoves(root->right, moves) + root->val - 1;
        moves += abs(balance);
        return balance;
    }
    int distributeCoins(TreeNode* &root) {
        int moves = 0;
        countMoves(root, moves);
        return moves;
    }
};