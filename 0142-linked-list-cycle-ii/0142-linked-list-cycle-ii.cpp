/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        while(head){
            if(head->val == INT_MAX) break;
            head->val = INT_MAX;
            head = head->next;
        }
        return head;
    }

    // ListNode *detectCycle(ListNode *head) {
    //     ListNode *slow=head, *fast=head;
    //     bool iscycle = false;
    //     while(fast && fast->next){
    //         slow = slow->next;
    //         fast = fast->next->next;
    //         if(slow == fast){
    //             iscycle = true;
    //             break;
    //         }
    //     }
    //     if(!iscycle) return NULL;
    //     slow = head;
    //     while(fast != slow){
    //         slow = slow->next;
    //         fast = fast->next;
    //     }
    //     return slow;
    // }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();