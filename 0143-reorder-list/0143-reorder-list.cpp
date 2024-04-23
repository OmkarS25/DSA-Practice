class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode* slow = head;
        ListNode* fast = head;

        // Finding the middle of linked list
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        // Reverse the second half of linked list
        ListNode* prev = NULL;
        ListNode* curr = slow->next;
        slow->next = NULL;
        while(curr){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        //Merge the first half and the reversed second half
        ListNode* first = head;
        ListNode* second = prev;
        while (second) {
            ListNode* nextFirst = first->next;
            ListNode* nextSecond = second->next;
            first->next = second;
            second->next = nextFirst;
            first = nextFirst;
            second = nextSecond;
        }
    }
};


// This is my core logic and the above one is the optimized one.
// void reorderList(ListNode* head) {
//     if (!head || !head->next) return;

//     ListNode* currentHead = head;
//     while (currentHead->next != NULL) {
//         ListNode* temp = currentHead;
//         ListNode* last = temp->next;
//         while (last->next != NULL) {
//             temp = last;
//             last = last->next;
//         }

//         if (temp == currentHead) break;

//         last->next = currentHead->next;
//         currentHead->next = last;
//         temp->next = NULL;
//         currentHead = last->next;
//     }
// }
