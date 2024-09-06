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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> list;
        for(int a : nums){
            list.insert(a);
        }
        while(true){
            if(list.find(head->val) != list.end()) 
                head = head->next;
            else 
                break;
        }
        ListNode *prev = head, *curr = head->next;
        while(curr){
            if(list.find(curr->val) != list.end())
                prev->next = curr->next;
            else 
                prev = curr;
            curr = curr->next;
        }
        return head;
    }
};