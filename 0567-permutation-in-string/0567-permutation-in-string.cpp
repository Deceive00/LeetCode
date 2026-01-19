class Solution {
public:
    bool isPermutation(unordered_map<char, int> map1, unordered_map<char, int>map2) {
        bool flag = true;
        for(auto it: map1) {
            if(map2.find(it.first) == map2.end()) {
                return false;
            } else {
                if (map2[it.first] != it.second) flag = false;
            }
        }
        return flag;
    }
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        int right = s1.length();
        unordered_map<char, int> map1, map2;
        for (int i = 0 ; i < right ; i++) {
            map1[s1[i]]++;
        }
        int start = 0;

        for (int i = 0 ; i < right ; i++) {
            map2[s2[i]]++;
        }
        if (isPermutation(map1, map2)) {
            return true;
        }
        for (int i = right ; i < s2.length() ; i++){
            map2[s2[i]]++;
            map2[s2[start++]]--;
            if (isPermutation(map1, map2)) {
                return true;
            }
        }
        return false;
    }
};