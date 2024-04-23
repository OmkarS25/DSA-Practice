class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode* currentHead = head;
        while (currentHead->next != NULL) {
            ListNode* temp = currentHead;
            ListNode* last = temp->next;
            while (last->next != NULL) {
                temp = last;
                last = last->next;
            }

            if (temp == currentHead) break;

            last->next = currentHead->next;
            currentHead->next = last;
            temp->next = NULL;
            currentHead = last->next;
        }
    }
};