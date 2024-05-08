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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2, result;

        // Push values of l1 into stack s1
        while (l1 != nullptr) {
            s1.push(l1->val);
            l1 = l1->next;
        }

        // Push values of l2 into stack s2
        while (l2 != nullptr) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;

        // Calculate sum and store result in stack
        while (!s1.empty() || !s2.empty() || carry != 0) {
            int sum = carry;
            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }
            carry = sum / 10;
            sum %= 10;
            result.push(sum);
        }

        // Construct result linked list
        ListNode* ans = new ListNode(0); // Dummy node
        ListNode* current = ans;
        while (!result.empty()) {
            current->next = new ListNode(result.top());
            result.pop();
            current = current->next;
        }

        return ans->next;
    }
};