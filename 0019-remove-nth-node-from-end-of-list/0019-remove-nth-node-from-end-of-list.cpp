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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slower = head;
        ListNode *faster = head;
        int length = 0;
        bool even = false;
        while(faster){

            if(faster->next && !faster->next->next) {
                even = true;
            }
            faster = faster->next ? faster->next->next : NULL;
            length++;
        }

        if(even) length = length * 2;
        else {

            length = length * 2;
            length--;

        }
        cout << length << endl;
        if(length == 1 && n == 1){
            return NULL;
        }
        int k = length - n;
        if(k < 0)   return NULL;
        if(k == 0) return head->next;
        ListNode *prev = new ListNode(-1);
        while(k > 0 && slower){
            if(k - 1 == 0 && slower->next){
                prev = slower;
                prev->next = slower->next->next;
                return head;
            }
            slower = slower->next;
            k--;
        }
        return NULL;
    }
};