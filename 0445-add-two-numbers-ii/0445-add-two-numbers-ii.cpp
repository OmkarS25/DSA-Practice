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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        while(curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;

        l1 = reverseList(l1);
        l2 = reverseList(l2);

        ListNode* ans = new ListNode();
        ListNode* current = ans; 
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry; 
            if (l1 != nullptr) {
                sum = sum + l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum = sum + l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            sum = sum % 10;
            current->next = new ListNode(sum); 
            current = current->next; 
        }

        return reverseList(ans->next);
    }
};
