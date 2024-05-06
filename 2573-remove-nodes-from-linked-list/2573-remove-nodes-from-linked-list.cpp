class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ios_base::sync_with_stdio(0);
        if(head==NULL)return head;
        head->next = removeNodes(head->next);
        if(head->next==NULL)return head;
        if(head->next->val>head->val)return head->next;
        return head;
    }
};

// If you want to save memory.
// if(!head->next) return head;
// stack<int> st;
// ListNode *temp=head;
// while(head){
//     while(!st.empty() && st.top()<temp->val){
//         st.pop();
//     }
//     st.push(head->val);
//     head = head->next;
//     delete temp;
//     temp = head;
// }
// ListNode* curr = NULL;
// while(!st.empty()){
//     head = new ListNode(st.top(),curr);
//     st.pop();
//     curr = head;
// }
// return head;