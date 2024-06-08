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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int count = 0;
        ListNode* temp = head;
        while(temp){
            count++;
            temp = temp->next;
        }
        k = k%count;
        while(k){
            ListNode *last = head, *secLast = head;
            while(last->next != NULL){
                last = last->next;
            }
            while(secLast->next != last){
                secLast = secLast->next;
            }
            secLast->next = NULL;
            last->next = head;
            head = last;
            k--;
        }
        return head;
    }
};