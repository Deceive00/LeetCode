class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int size = queries.size();
        int n = arr.size();
        vector<int> ans(size, -1);
        vector<int> prefixXor(n + 1, 0); 
        for (int i = 1; i <= n; i++) {
            prefixXor[i] = prefixXor[i - 1] ^ arr[i - 1];
        }
 
        for(int i = 0 ; i < size ; i++){
            int left = queries[i][0];
            int right = queries[i][1];
            ans[i] = prefixXor[right + 1] ^ prefixXor[left];
        } 
  
        return ans;  
    }
};