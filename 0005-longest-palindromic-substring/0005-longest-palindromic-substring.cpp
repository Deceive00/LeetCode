class Solution {
public:
    int max = 0;
    string maxString;
    void dfs(string s, long left, long right) {
        if (left >= right) return;
        int leftIter = left, rightIter = right;
        int isNotPalindrome = false;
        while (leftIter < rightIter) {
            if (s[leftIter] != s[rightIter]) {
                isNotPalindrome = true;
            }
            leftIter++; rightIter--;
        }
        if (!isNotPalindrome) {
            int length = right - left + 1;
            if (length >= max) {
                max = length;
                maxString = s.substr(left, length);
            }
        }
        dfs(s, left, right - 1);
        dfs(s, left + 1, right);
    }

    string longestPalindrome(string s) {
        // int left = 0, right = s.length() - 1;
        // maxString = s.substr(0, 1);
        // dfs(s, left, right);
        // return maxString;

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