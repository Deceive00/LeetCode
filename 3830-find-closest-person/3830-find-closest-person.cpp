class Solution {
public:
    int findClosest(int x, int y, int z) {
        int firstPersonDistance = abs(z - x);
        int secondPersonDistance = abs (z - y);

        if (firstPersonDistance < secondPersonDistance) {
            return 1;
        } else if (firstPersonDistance > secondPersonDistance) {
            return 2;
        } else {
            return 0;
        }
    }
};