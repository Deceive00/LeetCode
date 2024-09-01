class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int length = original.size();

        if(m * n < length || m * n > length || length == 0) return {};
        // int idx = 0;
        vector<vector<int>> ans;
        for(int i = 0 ; i < m ; i++){
            // for(int j = 0 ; j < n ; j++){
            //     ans[i][j] = original[idx++];
            // }
            ans.push_back(vector<int>(original.begin() + i * n, original.begin() + (i + 1) * n));
        }
        return ans;


    }
};