class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
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

        return ans->next; // Skipping the temp node which hold the head node.
    }
};