class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int curr = 1;
        int prev = curr;
        for(int i = 0 ; i < n ; i++){
            ans.push_back(curr);

            if(curr * 10 <= n){
                curr = curr * 10;
            } else {
                while(curr >= n || curr % 10 == 9){
                    curr = curr / 10;
                }
                curr++;
            }
        }
        return ans;
    }
};