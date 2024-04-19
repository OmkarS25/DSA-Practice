class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    int len = 1;
    struct ListNode* temp;
    temp = head;
    // To get the number of nodes we have
    while (temp->next != NULL){
        len++;
        temp = temp->next;
    }
    if(len == 1) return NULL;
    else if (len == n) return head->next; // If we need to remove the head.
    int del = len-n;
    temp = head;
    //Traversal to the previous node of which is going to get removed.
    for(int i=1; i<del; i++){
        temp = temp->next;
    }
    //Removing the node and the joining the list ahead of that node.
    temp->next = temp->next->next;
    return head;
    }
};