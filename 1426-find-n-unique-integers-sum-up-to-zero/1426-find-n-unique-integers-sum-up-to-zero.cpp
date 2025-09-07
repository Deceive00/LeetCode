class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        int isOdd = n % 2 != 0;
        if (isOdd) {
            res.push_back(0);
            n--;
        }

        for (int i = 1 ; i <= n / 2 ; i++) {
            res.push_back(i);
            res.push_back(-i);
        }
        return res;
    }
};