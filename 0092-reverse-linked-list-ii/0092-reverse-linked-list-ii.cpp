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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right)   return head;
        if(!head)   return NULL;
        ListNode *beforeReversedPtr = NULL;
        ListNode *start = head;
        int i = 1;
        while(i < left){
            beforeReversedPtr = start;
            start = start->next;
            i++;
        }

        ListNode *prev = beforeReversedPtr ? beforeReversedPtr : NULL;
        int length = right - left;
        ListNode *last = start;
        while(start && length >= 0){
            ListNode *next = start->next;
            start->next = prev;
            if(length == 0){
                if (beforeReversedPtr) {
                    beforeReversedPtr->next = start;
                } else {
                    head = start;
                }
                last->next = next;
            }
            prev = start;
            start = next;
            length--;
        }
        return head;

    }
};