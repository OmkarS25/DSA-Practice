/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        stack<int> st;
        ListNode *temp=head;
        st.push(0);
        while(head){
            st.push(head->val);
            head = head->next;
            delete temp;
            temp = head;
        }
        ListNode* curr = NULL; 
        int carry = 0;
        while(!st.empty()){
            int value = (st.top()*2 + carry)%10;
            carry = (st.top()*2)/10;
            head = new ListNode(value,curr);
            st.pop();
            curr = head;
        }
        if(head->val == 0) return head->next;
        return head;
    }
};