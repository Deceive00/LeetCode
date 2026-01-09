class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxCount = 0;
        int count = 0;
        int startIdx = 0;
        unordered_map<char, int> map;
        for (int i = 0 ; i < s.length() ; i++) {
            char c = s[i];
            if (map.find(c) != map.end()) {
                if (startIdx > map[c]) {
                    count++;
                    maxCount = max(maxCount, count);
                    map[c] = i;
                } else {
                    maxCount = max(maxCount, count);
                    count = i - map[c]; 
                    startIdx = map[c] + 1;
                    map[c] = i;
                }
            } else {
                map[c] = i;
                count++;
            }
        }
        maxCount = max(maxCount, count); 
        return maxCount;
    }
};