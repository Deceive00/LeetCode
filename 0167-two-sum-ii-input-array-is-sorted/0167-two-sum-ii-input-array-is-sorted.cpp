class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int lower = 0, upper = numbers.size() - 1;
        while(lower < upper){
            if(numbers[lower] + numbers[upper] > target){
                upper--;
            } else if(numbers[lower] + numbers[upper] < target){
                lower++;
            } else {
                break;
            }
        }
        return {lower + 1, upper + 1};
    }
};