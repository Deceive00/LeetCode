class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxElement = *max_element(nums.begin(), nums.end());
        int maxLength = 1;
        int counter = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == maxElement){
                counter++;
                if(maxLength < counter) maxLength = counter;
                
            }
            else counter = 0;
        }
        return maxLength;
    }
};