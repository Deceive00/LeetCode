class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> map;

        for(int a : arr1){
            int temp = a;
            while(temp > 0){
                map.insert(temp);
                temp /= 10;
            }
        }
        int longest = 0;
        for(int b : arr2){
            int temp = b;
            int counter = 0;
            int size = to_string(temp).size();
            while(temp > 0){
                if(map.find(temp) != map.end() && size > longest){
                    longest = size;
                }
                temp /= 10;
                size--;
            }
        }
        return longest;
    }
};