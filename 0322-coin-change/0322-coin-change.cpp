class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> cc(coins.size() + 1, vector<int>(amount + 1, INT_MAX));

        for(int i = 0; i < coins.size(); i++) {
            cc[i][0] = 0;
        }
        if(amount == 0) return 0;
        for(int i = 0 ; i < coins.size() ; i++){
            for(int j = 0 ; j <= amount ; j++){
                if(coins[i] <= j){
                    cc[i][j] = min(
                        i - 1 >= 0 ? cc[i - 1][j] : INT_MAX, 
                        cc[i][j - coins[i]] == INT_MAX ? INT_MAX : cc[i][j - coins[i]] + 1);
                } else {
                    if(i - 1 >= 0){
                        cc[i][j] = cc[i - 1][j];
                    } 
                }
            }
        }

        return cc[coins.size() - 1][amount] == INT_MAX ? -1 : cc[coins.size() - 1][amount];
    }
};