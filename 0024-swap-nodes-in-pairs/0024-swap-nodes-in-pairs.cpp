class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* dummynode = new ListNode();
        ListNode *ptr1=head, *ptr2=head->next, *curr=dummynode;
        dummynode->next = head;
        while(ptr1 && ptr2){
            ptr1->next = ptr2->next;
            ptr2->next = ptr1;
            curr->next = ptr2;
            curr = ptr1;
            ptr1 = ptr1->next;
            if(ptr1) ptr2 = ptr1->next;
        }
        ListNode* res = dummynode->next;
        delete dummynode;
        return res;
    }
};