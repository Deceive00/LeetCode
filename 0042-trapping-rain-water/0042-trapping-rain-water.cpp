class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        int maxElement = height[0];
        vector<int> prefixMax(size), postfixMax(size);
        prefixMax[0] = 0;
        for (int i = 1 ; i < size ; i++) {
            prefixMax[i] = max(height[i - 1], prefixMax[i - 1]);
        }
        postfixMax[size - 1] = 0;
        for (int i = size - 2 ; i > 0 ; i--) {
            postfixMax[i] = max(height[i + 1], postfixMax[i + 1]);
        }

        int water = 0;
        for (int i = 0 ; i < height.size() ; i++) {
            int temp = min(prefixMax[i], postfixMax[i]) - height[i];
            if (temp > 0) {
                water += temp; 
            }
        }
        return water;
    }
};