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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int remainders = 0;
        if(!l1 && !l2)  return NULL;
        else if(!l1)    return l2;
        else if(!l2) return l1;
        ListNode *head = new ListNode(-1);
        ListNode *curr = head;
        while(l1 || l2){
            int second = l2 ? l2->val : 0;
            int first = l1 ? l1->val : 0;
            int total = first + second + remainders;
            if(total >= 10){
                total = total % 10;
                remainders = 1;
            } else {
                remainders = 0;
            }
            curr->next = new ListNode(total);
            if(l1)  l1 = l1->next;
            if(l2)  l2 = l2->next;
            curr = curr->next;
        }
        if(remainders != 0){
            curr->next =  new ListNode(remainders);
        }
        return head->next;
    }
};