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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k, nullptr);
        ListNode *curr = head;
        int length = 0;
        while(curr){
            curr = curr->next;
            length++;
        }
        curr = head;
        int size = length / k;
        int ansIdx = 0;
        int extra = length > size * k ? length % k : 0;
        int counter = size;
        while(curr){
            counter = size;
          if(extra > 0){
            extra--;
            counter++;
          }      
          ListNode *currHead = curr;
          for(int i = 0 ; i < counter - 1 && curr->next ; i++){
            curr = curr->next;
          }
          ListNode *next = curr->next;
          curr->next = nullptr;
          ans[ansIdx] = currHead;
          ansIdx++;
          curr = next;
        }
        return ans;
    }
};