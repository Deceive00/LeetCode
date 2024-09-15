class Solution {
public:
    int findTheLongestSubstring(string s) {
        string vowels = "aiueo";
        int ans = 0, mask = 0;
        unordered_map<int, int> map;
        map[0] = -1;

        for(int i = 0 ; i < s.length() ; i++){
            if(vowels.find(s[i]) != std::string::npos){
                cout << "tes";
                mask = mask ^ (1 + s[i] - 'a');
            }
            if(map.find(mask) != map.end()){
                int currLength = i - map[mask];
                ans = max(ans, currLength);
            } else {
                map[mask] = i;
            }
        }
        return ans;
    }
};