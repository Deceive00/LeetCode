class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans;
        int maxSpeed = *max_element(piles.begin(), piles.end()), minSpeed = 0;
        while(minSpeed <= maxSpeed){
            int mid = minSpeed + (maxSpeed - minSpeed) / 2;
            int hour = 0;
            for(int i = 0 ; i < piles.size() && mid > 0 ; i++){
                hour += (int)ceil((double)piles[i] / mid);
            }

            if(hour <= h && mid > 0){
                ans = mid;
                maxSpeed = mid - 1;
            } else {
                minSpeed = mid + 1;
            }

        }
        return ans;
    }
};