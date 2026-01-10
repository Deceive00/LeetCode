class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        
        for (int i = 0 ; i < s.size() ; i++) {
            if (s[i] == ']') {
                string temporaryString = "";
                while(st.top() != '[') {
                    temporaryString = st.top() + temporaryString;
                    st.pop();
                }
                st.pop();
                string numberString = "";
                while(!st.empty() && st.top() >= '0' && st.top() <= '9') {
                    numberString = st.top() + numberString;
                    st.pop();
                }
                int totalRepetition = stoi(numberString);
                string repeatedWords = "";
                for (int i = 0 ; i < totalRepetition ; i++) {
                    repeatedWords = repeatedWords + temporaryString;
                }

                for (char c : repeatedWords) {
                    st.push(c);
                }
                cout << totalRepetition << " " << temporaryString << endl;
                
            } else {
                st.push(s[i]);
            }
        }
        string res = "";
        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};