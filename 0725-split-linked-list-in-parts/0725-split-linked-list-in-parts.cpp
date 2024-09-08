static const auto init = [](){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        if(k == 1) return {head};
        vector<ListNode*> ans (k, NULL);
        if(!head) return ans;
        int length = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            length++;
        }
        if(length <= k){
            ListNode *curr = head, *nxt = head->next;
            for(int i=0; i<length; i++){
                nxt = curr->next;
                ans[i] = curr;
                curr->next =  NULL;
                curr = nxt;
            }
        }
        else{
            int parts = (length/k) -1, remainder = length%k;
            ListNode *curr = head, *nxt;
            for(int i=0; i<k; i++){
                ans[i] = curr;
                int tmp = parts;
                while(tmp){
                    curr =  curr->next;
                    tmp--;
                }
                if(remainder){
                    curr = curr->next;
                    remainder--;
                }
                nxt = curr->next;
                curr->next = NULL;
                curr = nxt;
            }
        }
        return ans;
    }
};