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
        ListNode *slow=head, *fast=head;
        bool iscycle = false;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                iscycle = true;
                break;
            }
        }
        if(!iscycle) return NULL;
        slow = head;
        while(fast != slow){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};