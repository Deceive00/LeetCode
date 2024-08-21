class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        for(string& s : strs){
            bool match = false;
            string target = s;
            sort(target.begin(), target.end());

            map[target].push_back(s);
            // for(auto& it: map){
            //     string key = it.first;
            //     if(target == key){
            //         map[key].push_back(s);
            //         match = true;
            //         break;
            //     }   
            // }

            // if(!match){
            //     map[target].push_back(s);
            // }
        }
        vector<vector<string>> result;
        for (auto& it : map) {
            result.push_back(it.second); 
        }
        return result;
    }
};