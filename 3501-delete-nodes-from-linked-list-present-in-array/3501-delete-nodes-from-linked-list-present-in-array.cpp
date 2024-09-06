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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> numToDelete(nums.begin(), nums.end());
        if(nums.size() <= 0)    return head;

        ListNode *curr = head;
        ListNode *prev = NULL;
        while(curr){
            if(numToDelete.find(curr->val) != numToDelete.end()){
                if(!prev){
                    head = head->next;
                    curr = head;
                } else {
                    prev->next = curr->next;
                    curr = curr->next;
                }
            } else {
                prev = curr;
                curr = curr->next;
            }

        }
        return head;
    }
};