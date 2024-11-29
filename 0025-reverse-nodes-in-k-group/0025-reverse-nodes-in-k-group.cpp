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
    int lengthOfLL(ListNode *head){
        ListNode *temp = head;
        int len = 0;
        while(temp){
            temp = temp->next;
            len++;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next) return head;

        // 1 case mein solve karunga
        ListNode *prev=NULL, *curr=head;
        ListNode *nextNode = curr->next;
        int pos = 0;

        while(pos < k && curr != NULL){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            pos++;
        }

        if(nextNode != NULL && lengthOfLL(nextNode) >= k){
            head->next = reverseKGroup(nextNode, k);
        }
        else {
            head->next = nextNode;
        }
        return prev;
    }
};