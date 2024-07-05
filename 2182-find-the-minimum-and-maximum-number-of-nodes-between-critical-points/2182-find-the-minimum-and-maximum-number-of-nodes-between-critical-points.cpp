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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> criticalpoints;
        ListNode *prev = nullptr, *curr = head;
        int position = 0;
        while(curr && curr->next){
            if(prev && curr->next){
                if((curr->val > prev->val && curr->val > curr->next->val) || 
                (curr->val < prev->val && curr->val < curr->next->val)){
                    criticalpoints.push_back(position);
                }
            }
            prev = curr;
            curr = curr->next;
            position++;
        }
        if(criticalpoints.size() < 2) return {-1,-1};
        int minDis = INT_MAX;
        int maxDis = criticalpoints.back() - criticalpoints.front();
        for(int i=1; i<criticalpoints.size(); i++){
            minDis = min(minDis, criticalpoints[i] - criticalpoints[i - 1]);
        }
        return {minDis, maxDis};
    }
};