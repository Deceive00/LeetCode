class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        int len = temperatures.size();
        vector<int> ans(len);
        for(int i = 0 ; i < len ; i++){
            ans[i] = 0;
            while(!st.empty() && st.top().second < temperatures[i]){
                ans[st.top().first] = i - st.top().first;
                st.pop();
            }
            st.push({i, temperatures[i]});
        }
        return ans;
    }
};