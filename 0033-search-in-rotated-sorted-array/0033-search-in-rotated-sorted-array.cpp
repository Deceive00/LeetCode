class Solution {
public:
    int search(vector<int>& nums, int target) {
      int left = 0, right = nums.size() - 1;
        if(nums[0] == target){
            return 0;
        } else if(nums[right] == target){
            return right;
        }
      while(left < right){
        int mid = left + (right - left) / 2;
        if(nums[mid] == target){
            return mid;
        } 
        if(nums[mid] >= nums[0]){
            if(nums[mid] > target){
                if(target < nums[0]){
                    left = mid + 1;
                } else {
                    right = mid;
                }
            } else { // nums[mid] < target
                if(target > nums[0]){
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            
        } else if(nums[mid] < nums[0]) {
            if(nums[mid] > target){
                if(target < nums[0]){
                    right = mid;
                } else {
                    left = mid + 1;
                }
            } else if(nums[mid] < target){
                if(target < nums[0]){
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
        }

      }  
      return -1;
    }

};