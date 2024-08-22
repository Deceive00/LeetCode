class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;

        for(int n : nums){
            map[n]++;    
        }
        vector<pair<int, int>> vec; 
        copy(map.begin(), map.end(), back_inserter(vec)); 

        sort(vec.begin(), vec.end(), [](auto& a, auto& b)-> bool { 
            return a.second > b.second;
        });
        vector<int> result;
        for(auto& it : vec){
            if(k > 0){
                result.push_back(it.first);            
                k--;  
            }
        }
        return result;
    }
};