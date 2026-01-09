class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxSum = 0;

        for (int i = 0 ; i < k ; i++) {
            maxSum += nums[i];
        }

        int sum = maxSum;
        for (int i = k ; i < nums.size() ; i++) {
            sum += (nums[i] - nums[i - k]);
            maxSum = max(maxSum, sum);
        }
        return (double) maxSum / k;
    }
};