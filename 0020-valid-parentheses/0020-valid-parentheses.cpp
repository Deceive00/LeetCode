class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        int len = s.length();
        for(int i = 0 ; i < len ; i++){ 
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stack.push(s[i]);
                continue;
            } 

            else {
                if (stack.empty()) return false;
                char pop = stack.top();

                if((s[i] == ')' && pop != '(') ||
                    (s[i] == ']' && pop != '[') || 
                    (s[i] == '}' && pop != '{')){
                    return false;
                }

                stack.pop();
            }   
        }
        return stack.empty();
    }
};