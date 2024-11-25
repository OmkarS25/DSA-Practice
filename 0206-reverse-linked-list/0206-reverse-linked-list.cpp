// #pragma GCC optimize("O3", "unroll-loops") 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        stack<int> st;
        ListNode *curr=head;
        while(curr){
            st.push(curr->val);
            curr = curr->next;
        }
        curr = head;
        while(!st.empty()){
            curr->val = st.top();
            st.pop();
            curr = curr->next;
        }
        return head;
    }
};