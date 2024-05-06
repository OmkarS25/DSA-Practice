class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if(!head->next) return head;
        stack<int> st;
        ListNode *temp=head;
        while(head){
            while(!st.empty() && st.top()<temp->val){
                st.pop();
            }
            st.push(head->val);
            head = head->next;
            delete temp;
            temp = head;
        }
        ListNode* curr = NULL;
        while(!st.empty()){
            head = new ListNode(st.top(),curr);
            st.pop();
            curr = head;
        }
        return head;
    }
};