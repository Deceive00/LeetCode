class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;

       for(int n : nums){
        if(map[n] == 1){
            return true;
        }
        map[n] = 1;
        
       }
       return false;
    }
};
