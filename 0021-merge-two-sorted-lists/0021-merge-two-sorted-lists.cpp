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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ptr1 = list1, *ptr2 =  list2, *curr = NULL;
        ListNode* head = new ListNode();
        curr = head;
        while(ptr1 && ptr2){
            if(ptr1->val > ptr2->val){
                curr->next = new ListNode(ptr2->val);
                curr = curr->next;
                ptr2 =  ptr2->next;
            }
            else {
                curr->next = new ListNode(ptr1->val);
                curr = curr->next;
                ptr1 =  ptr1->next;
            }
        }
        while(ptr1){
            curr->next = new ListNode(ptr1->val);
            curr = curr->next;
            ptr1 =  ptr1->next; 
        }
        while(ptr2){
            curr->next = new ListNode(ptr2->val);
            curr = curr->next;
            ptr2 =  ptr2->next; 
        }
        return head->next;
    }
};