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

        head->next = (nextNode != NULL && lengthOfLL(nextNode) >= k) ? reverseKGroup(nextNode, k) : nextNode;

        return prev;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();