/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head){
            return false;
        }

        ListNode *slower = head;
        ListNode *faster = head->next;
        while(slower != faster){
            if(slower == NULL || faster == NULL){
                return false;
            }
            slower = slower->next ? slower->next : NULL;
            if(faster->next && faster->next->next){
                faster = faster->next->next;
            } else {
                faster = NULL;
            }
        }
        return true;
    }
};