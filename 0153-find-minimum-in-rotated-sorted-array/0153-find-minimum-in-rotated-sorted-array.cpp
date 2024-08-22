class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int min = 5001;
        if(right == left){
            return nums[0];
        }
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(min > nums[mid]){
                min = nums[mid];
            }
            if(nums[mid] <= nums[0]){
                right = mid;
            } else if(nums[mid] > nums[0]){
                left = mid + 1;
            }

            if(left == right){
                break;
            }
        }
        if(min > nums[0]) min = nums[0];
        if(min > nums[nums.size() - 1]) min = nums[nums.size() - 1];
        

        return min;        
    }
};