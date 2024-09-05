class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = accumulate(rolls.begin(), rolls.end(), 0);
        int m = rolls.size();
        

        int nSum = mean * (n + m) - sum;
    
        if (nSum < n || nSum > 6 * n) {
            return {};
        }
        
        vector<int> ans(n, 1); 
        nSum -= n;  

        for (int i = 0; i < n && nSum > 0; ++i) {
            int add = min(5, nSum); 
            ans[i] += add;
            nSum -= add;
        }
        
        return ans;
    }
};
