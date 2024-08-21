class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int max = -1;
        for(int i = 0, j = size - 1 ; i < j ;){
            int h = height[i] > height[j] ? height[j] : height[i];
            int length = j - i;
            int newArea = h * length;
            if(newArea > max){
                max = newArea;
            }
            if(height[i] < height[j]){
                i++;
                continue;
            } else{
                j--;
                continue;
            }

            i++; j--;
        }
        return max;
    }
};