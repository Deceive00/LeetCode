class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0, zeroCounter = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] != 0){
                nums[idx] = nums[i];
                idx++;
            } else {
                zeroCounter++;
            }
        }
        while(zeroCounter > 0 && idx < nums.size()){
            nums[idx] = 0;
            idx++;
        }
        return;
    }
};