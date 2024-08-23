class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int lenI = nums1.size(), lenJ = nums2.size();
        int totalLen = (lenI + lenJ);
        int medianIdx =  totalLen / 2;
        vector<int> vec;
        while(i < lenI && j < lenJ){
            if(nums1[i] < nums2[j]){
                vec.push_back(nums1[i]);
                i++;
            } else {
                vec.push_back(nums2[j]);
                j++;
            }
        }

        while(i < lenI){
            vec.push_back(nums1[i]);
            i++;       
        }
        while(j < lenJ){
            vec.push_back(nums2[j]);
            j++;    
        }

        if(totalLen % 2 == 0){
            return (vec[medianIdx] + vec[medianIdx - 1]) / 2.0;
        } else {
            return vec[medianIdx];
        }
    }
};