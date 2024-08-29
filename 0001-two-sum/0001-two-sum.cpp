class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> number;
        int i = 0;
        for(int num : nums){
            int comp = target - num;
            if(number.count(comp)){
                return {number[comp], i};
            } 
            cout << num;
            number[num] = i;
            i++;
        }
        return {};
    }
};