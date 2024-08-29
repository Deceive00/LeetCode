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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> numbers;

        for(ListNode *node : lists){
            ListNode *curr = node;
            while(curr){
                numbers.push(curr->val);
                curr = curr->next;
            }
        }
        ListNode *head = new ListNode(-1);
        ListNode *prev = head;
        while(!numbers.empty()){
            cout << numbers.top() << endl;
            ListNode *newNode = new ListNode(numbers.top());
            prev->next = newNode;
            prev = newNode;
            numbers.pop();
        }

        return head->next;
    }
};
