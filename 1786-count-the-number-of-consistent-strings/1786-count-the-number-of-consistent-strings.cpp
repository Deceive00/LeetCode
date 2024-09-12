class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int arr[27] = {0};
        for(int i = 0 ; i < allowed.length() ; i++){
            arr[allowed[i] - 'a']++;
        }
        int count = 0;
        for(int i = 0 ; i < words.size(); i++){
            bool valid = true;
            string w = words[i];
            for(int j = 0 ; j < w.length() ; j++){
                if(arr[w[j] - 'a'] == 0){
                    valid = false;
                    break;
                }
            }
            if(valid){
                count++;
            }
        }
        return count;
    }   
};