class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int k = 0;
        int res = INT_MAX;
        int i = 1, j = piles[piles.size() - 1];
        long currentHour;
        // 4 11 20 23 30 h = 6
        while (i <= j) {
            k = i + (j - i) / 2;
            currentHour = 0;
            for (int z = 0 ; z < piles.size(); z++) {
                currentHour += ceil((double)piles[z] / k);
            }
            cout << i << " "<< j << " " << k << " " << currentHour << endl;
            if (currentHour > h) {
                i = k + 1;
            } else {
                j = k - 1;
                if(currentHour == h) {
                    res = min(k, res);
                } else {
                    res = k;
                }
            }
        }
        // base conditionnya ga harus h == currentHour
        return res;
    }
};