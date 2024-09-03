class Solution {
public:
    int getLucky(string s, int k) {
        string converted = "";
        for(int i = 0 ; i < s.length() ; i++){
            converted += to_string((int)s[i] - 'a' + 1);
        }
        int num; 
        while(k > 0){
            num = 0;
            for(int i = 0 ; i < converted.length() ; i++){
                num += int(converted[i] - '0');
            }
            converted = to_string(num);
            k--;
        }
        return num;
    }
};