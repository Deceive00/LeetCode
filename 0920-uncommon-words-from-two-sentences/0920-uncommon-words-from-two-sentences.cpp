class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> map;
        istringstream iss(s1);
        istringstream iss2(s2);
        string word;
        while (iss >> word) {
            map[word]++;
        }
        while (iss2 >> word) {
            map[word]++;
        }
        vector<string> ans;
        for(auto m : map){
            if(m.second == 1){
                ans.push_back(m.first);
            }
        }
        return ans;
    }
};