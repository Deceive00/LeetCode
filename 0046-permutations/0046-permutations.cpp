class Solution {
public:
    vector<vector<int>> res;

    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void dfs(vector<int> nums, int i, int n) {
        if (i == n) {
            res.push_back(nums);
            return;
        }

        for(int j = i ; j < nums.size() ; j++) {
            swap(nums[i], nums[j]);
            dfs(nums, i + 1, n);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ans;
        dfs(nums, 0, nums.size());
        return res;
    }
};