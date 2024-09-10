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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *curr = head;
        while(curr){
            if(curr->next){
                ListNode *next = curr->next;

                ListNode *newNode = new ListNode(gcd(curr->val, curr->next->val));
                newNode->next = next;
                curr->next = newNode;
                curr = next;
            } else {
                curr = curr->next;
            }
            
        }
        return head;
    }
};