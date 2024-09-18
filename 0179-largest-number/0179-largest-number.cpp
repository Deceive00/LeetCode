class Solution {
public:
    static bool cmpr(string a, string b){
        if(a + b > b + a){
            return true;
        } else {
            return false;
        }
    }
    string largestNumber(vector<int>& nums) {
        vector<string> strNums;
        long long int sum = 0;
        for(int n : nums){
            strNums.push_back(to_string(n));
            sum += n;
        }
        if(sum == 0) return "0";
        sort(strNums.begin() , strNums.end(), cmpr);
        string ans = "";
        for(string s : strNums){
            ans += s;
        }
        return ans;
    }
};