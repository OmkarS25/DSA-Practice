class Solution {
public:
    void deleteNode(ListNode* node) {
        while(node->next->next){
            node->val = node->next->val; 
            node = node->next;
        }
        node->val = node->next->val;
        delete node->next;
        node->next = NULL;
    }
};