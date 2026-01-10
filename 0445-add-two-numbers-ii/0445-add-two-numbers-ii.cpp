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
        stack<int> firstStack, secondStack;
        ListNode *curr = l1;
        while(curr) {
            firstStack.push(curr->val);
            curr = curr->next;
        }
        curr = l2;
        while(curr) {
            secondStack.push(curr->val);
            curr = curr->next;
        }
        ListNode *head = nullptr;
        int remaining = 0;
        int value = 0;
        while(!firstStack.empty() && !secondStack.empty()) {
            value = remaining + firstStack.top() + secondStack.top();
            if (value >= 10) {
                remaining = value / 10;
                value = value % 10;
            } else remaining = 0;
            curr = new ListNode(value, head);
            head = curr;
            firstStack.pop();secondStack.pop();
        }

        while (!firstStack.empty()) {
            value = remaining + firstStack.top();
            if (value >= 10) {
                remaining = value / 10;
                value = value % 10;
            } else remaining = 0;
            curr = new ListNode(value, head);
            head = curr;
            firstStack.pop();
        }
        while (!secondStack.empty()) {
            value = remaining + secondStack.top();
            if (value >= 10) {
                remaining = value / 10;
                value = value % 10;
            } else remaining = 0;
            curr = new ListNode(value, head);
            head = curr;
            secondStack.pop();
        }

        if (remaining > 0) {
            curr = new ListNode(remaining, head);
            head = curr;
        }
        return head;
        
    }
};