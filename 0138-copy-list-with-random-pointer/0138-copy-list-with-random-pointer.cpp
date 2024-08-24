/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)   return head;
        Node *curr = head;
        vector<Node*> real;
        while(curr){
            cout << curr << " " << curr->next << " " << curr->random << endl;
            real.push_back(curr->next);
            Node *copy = new Node(curr->val);
            copy->next = curr->next;
            copy->random = curr->random;
            curr->next = copy;
            curr = copy->next;
        }
        curr = head->next;
        while(curr && curr->next){
            curr->next = curr->next->next;
            curr->random = curr->random ? curr->random->next : NULL;
            curr = curr->next;
        }
        curr->random = curr->random ? curr->random->next : NULL;
        // cout << endl << endl;
        curr = head->next;
        while(curr){
            // cout << curr << " " << curr->next << " " << curr->random << " " << curr->val << endl;
            curr = curr -> next;
        }
        Node *copy = head->next;
        curr = head;
        int i = 0;
        while(curr){
            curr->next = real[i];
            i++;
            curr = curr->next;
        }
        return copy;
    }
};