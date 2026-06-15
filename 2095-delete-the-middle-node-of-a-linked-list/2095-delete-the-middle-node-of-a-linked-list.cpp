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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next) return nullptr;
        ListNode *slow = head, *fast = head, *slow_prev = head;
        while(fast && fast->next){
            slow_prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        slow_prev->next = slow->next;
        return head;
    }
};