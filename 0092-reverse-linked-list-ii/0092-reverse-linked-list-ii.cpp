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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next) return head;
        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        stack<int> st;
        ListNode *curr=head;
        int count = 0;
        while(curr && count<right){
            count++;
            if(count>=left)
            st.push(curr->val);
            curr = curr->next;
        }
        curr = head;
        count = 0;
        while(!st.empty() && count<right){
            count++;
            if(count>=left){
            curr->val = st.top();
            st.pop();
            }
            curr = curr->next;
        }
        return head;  
    }
};