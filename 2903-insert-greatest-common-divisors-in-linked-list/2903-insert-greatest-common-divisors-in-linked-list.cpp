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

static const auto init = [](){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    int gcd(int a, int b) {
        int result = min(a, b);
        while (result > 0) {
            if (a % result == 0 && b % result == 0)
                break;
            result--;
        }
        return result;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head->next) return head;
        ListNode *prev = head, *curr = head->next;
        while(curr){
            int num = gcd(prev->val, curr->val);
            ListNode *middle = new ListNode(num, curr);
            prev->next = middle;
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};