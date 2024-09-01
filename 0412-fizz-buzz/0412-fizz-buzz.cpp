class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for(int i = 1 ; i <= n ; i++){
            string a;
            if(i % 3 == 0 && i % 5 == 0){
                a = "FizzBuzz";
            } else if(i % 3 == 0){
                a = "Fizz";
            } else if (i % 5 == 0){
                a = "Buzz";
            } else {
                a = to_string(i);
            }
            ans.push_back(a);
        }
        return ans;
    }
};