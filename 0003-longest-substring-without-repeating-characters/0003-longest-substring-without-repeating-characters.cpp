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
                maxCount = max(maxCount, count);
                if (startIdx > map[c]) {
                    count++;
                    map[c] = i;
                } else {
                    count = i - map[c]; 
                    startIdx = map[c] + 1;
                    map[c] = i;
                }

                cout << c << " " << count << " " << startIdx << " " << map[c] << endl;
            } else {
                map[c] = i;
                count++;
                cout << c << " " << count << endl;
            }
        }
        maxCount = max(maxCount, count); 
        return maxCount;
    }
};