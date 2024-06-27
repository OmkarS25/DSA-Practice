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
    ListNode* sortList(ListNode* head) {
        if(head==NULL) return head;
        sortList(head->next);
        ListNode* temp=head;
        while(temp->next && temp->val>temp->next->val){
            swap(temp->val,temp->next->val);
            temp=temp->next;
        }
        return head;

        // ListNode *dummyHead = new ListNode(), *temp = head;
        // vector<int> list;
        // while(temp){
        //     list.push_back(temp->val);
        //     temp = temp->next;
        // }
        // sort(list.begin(), list.end());
        // temp = dummyHead;
        // for(int a : list){
        //     temp->next = new ListNode(a);
        //     temp = temp->next;
        // }
        // return dummyHead->next;
    }
};