class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        if(nums[i] == target){
            return i;
        } 
        else if(nums[j] == target){
            return j;
        }
        while(i <= j){
            int mid = i + (j - i) / 2;
            if(nums[mid] == target){
                return mid;
            } else if(nums[mid] > target){
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        return -1;
    }
};
