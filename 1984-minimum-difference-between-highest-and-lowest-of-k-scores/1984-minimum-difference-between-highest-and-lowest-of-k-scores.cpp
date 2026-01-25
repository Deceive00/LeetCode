class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int currentMin = INT_MAX;
        for (int i = 0 ; i < nums.size() - k + 1 ; i++) {
            int diff = nums[i + k - 1] - nums[i];
            currentMin = min(currentMin, diff);
        }

        return currentMin;
    }
};