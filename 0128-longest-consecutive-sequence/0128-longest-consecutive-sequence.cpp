class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> map;
        int maxCounter = 0;
        int n = nums.size();

        for(int i = 0 ; i < n ; i++){
            map.insert(nums[i]);
        }    
        if(map.size() == 1){
            return 1;
        }
        for(int it : map){
            int counter = 1;
            if(map.find(it - 1) == map.end()){
                int currentNumber = it;
                while(map.find(currentNumber + 1) != map.end()){
                    currentNumber++;
                    counter++;
                }
            }
            if(maxCounter < counter){
                maxCounter = counter;
            }


        } 

        
        return maxCounter;
    }
};