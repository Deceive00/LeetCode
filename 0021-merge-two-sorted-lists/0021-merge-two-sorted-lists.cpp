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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL & list2 == NULL){
            return NULL;
        }
        ListNode *curr = NULL;
        ListNode *beforeHead = new ListNode(-101);

        if((list1 ? list1->val : 101) <= (list2 ? list2->val : 101)){
            beforeHead->next = list1;
            list1 = list1->next;
        } else {
            beforeHead->next = list2;
            list2 = list2->next;
        }
        curr = beforeHead->next;
        while(list1 || list2){
            int first = list1 ? list1->val : 101;
            int second = list2 ? list2->val : 101;
            if(first <= second){
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }

        return beforeHead->next;
    }
};