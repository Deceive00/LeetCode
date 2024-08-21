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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode *curr = head;
        while(curr){
            st.push(curr);
            curr = curr->next;
        } 
        int size = st.size();
        if(st.empty())  return;
        curr = head;
        while(curr && st.top() && st.top() != curr){
            if(curr->next != st.top()){
                ListNode* top = st.top();
                top->next = curr->next;
                curr->next = top;
                if(curr->next){
                    curr = curr->next->next;
                } else {
                    curr = NULL;
                }
                st.pop();
                
            } else {
                break;
            }
        }
        curr->next = st.top();
        curr->next->next = NULL;

    }
};