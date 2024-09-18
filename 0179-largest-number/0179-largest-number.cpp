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
        for(int n : nums){
            strNums.push_back(to_string(n));
        }
        sort(strNums.begin() , strNums.end(), cmpr);
        if(!strNums.empty() && strNums[0] == "0") return "0";
        string ans = "";
        for(string s : strNums){
            ans += s;
        }
        return ans;
    }
};