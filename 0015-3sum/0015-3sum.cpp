class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        int n = nums.size();
        set<vector<int>> ans;
        vector<vector<int>> vec;
        for(int i = 0 ; i < n - 2; i++){
            if(i > 0  && nums[i] == nums[i - 1]){
                continue;
            }
            int lower = i + 1, upper = nums.size() - 1;
            while(lower < upper){
                // cout << nums[i] << " " << nums[lower] << " " << nums[upper] << endl;
                if(lower < upper && nums[i] + nums[lower] + nums[upper] > 0){
                    upper--;
                }
                else if(lower < upper && nums[i] + nums[lower] + nums[upper] < 0){
                    lower++;
                }
                else{
                    if(nums[i] + nums[lower] + nums[upper] == 0 && 
                        lower != upper && i != lower && i != upper ){
                        ans.insert({nums[i], nums[lower], nums[upper]});
                        lower++;
                        upper--;
                    }
                }
            }
        }
        vec.assign(ans.begin(), ans.end());
        return vec;
    }
};