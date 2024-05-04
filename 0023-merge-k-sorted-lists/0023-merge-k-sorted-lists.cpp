class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (!list1)
            return list2;
        if (!list2)
            return list1;
        ListNode *ptr1 = list1, *ptr2 = list2;
        ListNode *head = new ListNode(0);
        ListNode *curr = head;
        while (ptr1 && ptr2)
        {
            if (ptr1->val < ptr2->val)
            {
                curr->next = ptr1;
                ptr1 = ptr1->next;
            }
            else
            {
                curr->next = ptr2;
                ptr2 = ptr2->next;
            }
            curr = curr->next;
        }
        if (ptr1)
            curr->next = ptr1;
        if (ptr2)
            curr->next = ptr2;
        ListNode *mergedList = head->next;
        delete head;                       
        return mergedList;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return NULL;
        int interval = 1;
        while (interval < lists.size())
        {
            for (int i = 0; i + interval < lists.size(); i += interval * 2)
            {
                lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }
        return lists[0];
    }
};