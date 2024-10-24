class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        int lastSame = -1;
        if(nums.size() <= 1) return nums.size();
        int i = 0, j = 1;
        while(i < nums.size() && j < nums.size()){
            while(j < nums.size() - 1 && nums[i] == nums[j]){
                j++;
            }
            i++;
            if(j > nums.size() - 1 || i > nums.size() - 1) break;
            nums[i] = nums[j];
            lastSame = nums[j];
        }

        for(int y = 1 ; y < nums.size() ; y++){
            if(nums[y] == nums[y - 1]) {
                return y;
            }
        }
        return i;
    }
};