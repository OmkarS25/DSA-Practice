static const auto init = [](){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int i = 0, j = 0, rightBorder = n, leftBorder = 0, downBorder = m, upBorder = 0;
        while (head) {
            // Move right
            while (j < rightBorder && head) {
                ans[i][j++] = head->val;
                head = head->next;
            }
            j--; i++; upBorder++;
            
            // Move down
            while (i < downBorder && head) {
                ans[i++][j] = head->val;
                head = head->next;
            }
            i--; j--; rightBorder--;
            
            // Move left
            while (j >= leftBorder && head) {
                ans[i][j--] = head->val;
                head = head->next;
            }
            j++; i--; downBorder--;
            
            // Move up
            while (i >= upBorder && head) {
                ans[i--][j] = head->val;
                head = head->next;
            }
            i++; j++; leftBorder++;
        }
        
        return ans;
    }
};
