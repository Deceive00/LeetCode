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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int i = 0, j = 0;
        int direction = 0;
        ListNode *curr = head;
        int topLimit = 0, leftLimit = 0;;
        // Direction -> kanan, bawah, kiri, atas (0-3)
        while(curr){
            if(i > m - 1 || j > n - 1) break;
            ans[i][j] = curr->val;
            curr = curr->next;
            // Move
            switch(direction){
                case 0:
                    j++;
                    break;
                case 1:
                    i++;
                    break;
                case 2:
                    j--;
                    break;
                case 3:
                    i--;
                    break;
            }
            // Changing direction
            if(direction == 3 && i == topLimit && j == leftLimit){
                topLimit++;
                leftLimit++;
                i = topLimit;
                j = leftLimit;
                m--;n--;
                direction = 0;
            }
            else if(i >= m || j >= n){
                direction++;
                direction %= 4;
                if(i >= m){
                    i = m - 1;
                    j--;
                }
                else {
                    j = n - 1;
                    i++;
                }
            }
            else if(i < topLimit || j < topLimit){
                direction++;
                direction %= 4;
                if(i < 0){
                    i = topLimit;
                    j++;
                }
                else{
                    j = topLimit;
                    i--;
                }
            }
        
        } 
        return ans;

    }
};