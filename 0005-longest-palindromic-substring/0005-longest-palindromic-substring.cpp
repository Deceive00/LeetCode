class Solution {
public:
    string longestPalindrome(string s) {

        int maxLeft = 0, length = 1;

        for(int i = 0 ; i < s.length() ; i++) {

            int left = i, right = i;
            // odd
            while (left >= 0 && left <= right && s[left] == s[right]) {
                if (right - left + 1 > length) {
                    maxLeft = left;
                    length = right - left + 1;
                }
                left--;right++;
            }
            left = i, right = i + 1;
            while (left >= 0 && left <= right && s[left] == s[right]) {
                if (right - left + 1 > length) {
                    maxLeft = left;
                    length = right - left + 1;
                }
                left--;right++;
            }
        }

        return s.substr(maxLeft, length);
    }
};