class Solution {
public:
    unordered_map<string, vector<int>> memo;
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        if(memo.find(expression) != memo.end()) return memo[expression];
        if(expression.length() <= 0)    return {};
        if(expression.length() == 1){
            ans.push_back(stoi(expression));
            return ans;
        }
        if (expression.length() == 2 && isdigit(expression[0])) {
            ans.push_back(stoi(expression));
            return ans;
        }
        for(int i = 0 ; i < expression.size() ; i++){
            if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*'){
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));
                
                for(int l : left){
                    for(int r : right){
                        switch(expression[i]){
                            case '+':
                                ans.push_back(l + r);
                                break;
                            case '*':
                                ans.push_back(l * r);
                                break;
                            case '-':
                                ans.push_back(l - r);
                                break;
                        }
                    }
                }
            }
        }
        memo[expression] = ans;
        return ans;
    }
};