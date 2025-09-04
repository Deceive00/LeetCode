class Solution {
public:
    bool isHappy(int n) {
        int curr = n;
        unordered_set<int> memo;
        if (curr == 1) return true;
        while (curr != 1) {
            if (memo.find(curr) != memo.end()) return false;
            memo.insert(curr);
            string nInString = to_string(curr);
            int newNumber = 0;
            for (int i = 0 ; i < nInString.length() ; i++) {
                newNumber += pow(((int) (nInString[i] - '0')), 2.0);
            }
            if (newNumber == 1) return true;
            curr = newNumber;
        }
        return false;
    }
};