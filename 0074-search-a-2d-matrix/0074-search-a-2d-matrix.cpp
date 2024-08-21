class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0, j = matrix.size() - 1;

        while(i <= j){
            int mid = i + (j - i) /2;
            if(matrix[mid][0] == target){
                return true;
            } else if(matrix[mid][0] < target){
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        int l = 0, r = matrix[0].size() - 1;

        while(l <= r){
            int mid = l + (r - l) /2;
            if(matrix.size() > j && matrix[j][mid] == target){
                return true;
            } else if(matrix.size() > j && matrix[j][mid] < target){
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return false;
    }
};