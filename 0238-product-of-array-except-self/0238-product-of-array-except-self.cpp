class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix;
        prefix.push_back(nums[0]);
        for(int i = 1 ; i < nums.size() ; i++){
            prefix.push_back(prefix[i - 1] * nums[i]);
        }

        vector<int> postfix;
        postfix.push_back(nums[nums.size() - 1]);
        for(int i = nums.size() - 2 ; i > 0 ; i--){
            postfix.insert(postfix.begin(), postfix[0] * nums[i]);
        }


        vector<int> result;
        for(int i = 0 ; i < nums.size() ; i++){
            int a = i == 0 ? 1 : prefix[i - 1];
            int b = i == nums.size() - 1 ? 1 : postfix[i];
            result.push_back(a * b);
        }
        return result;
    }
};
