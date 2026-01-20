class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        int start = 0;
        int windowSize = p.length();
        unordered_map<char, int> stringMap;
        unordered_map<char, int> queryMap;
        for (int i = 0 ; i < windowSize ; i++) {
            queryMap[p[i]]++;
        }
        // cout << s << endl;
        for(int i = 0 ; i < s.length() ; i++) {
            stringMap[s[i]]++;
            if(i - start + 1 == windowSize) {
                // cout << i << " " << start << " " << s <<endl;
                if (queryMap == stringMap) ans.push_back(start);
                stringMap[s[start]]--;
                if (stringMap[s[start]] == 0) stringMap.erase(s[start]);
                start++;
            }
        }

        return ans;
    }
};