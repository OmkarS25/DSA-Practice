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
    // ListNode *mergeTwoLists(ListNode *list1, ListNode *list2){
    //     if (!list1) return list2;
    //     if (!list2) return list1;
    //     ListNode *ptr1 = list1, *ptr2 = list2;
    //     ListNode *head = new ListNode(0);
    //     ListNode *curr = head;
    //     while (ptr1 && ptr2){
    //         if (ptr1->val < ptr2->val){
    //             curr->next = ptr1;
    //             ptr1 = ptr1->next;
    //         }
    //         else{
    //             curr->next = ptr2;
    //             ptr2 = ptr2->next;
    //         }
    //         curr = curr->next;
    //     }
    //     if (ptr1) curr->next = ptr1;
    //     if (ptr2) curr->next = ptr2;
    //     ListNode *mergedList = head->next;
    //     delete head;                       
    //     return mergedList;
    // }

    ListNode* sortList(ListNode* head) {
        ListNode *dummyHead = new ListNode(), *temp = head;
        vector<int> list;
        while(temp){
            list.push_back(temp->val);
            temp = temp->next;
        }
        sort(list.begin(), list.end());
        temp = dummyHead;
        for(int a : list){
            temp->next = new ListNode(a);
            temp = temp->next;
        }
        return dummyHead->next;
    }
};