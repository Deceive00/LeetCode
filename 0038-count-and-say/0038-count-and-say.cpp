class Solution {
public:
    string recursive(int iter, int max, string res) {
        if (iter >= max) return res;
        int index = 0;
        vector<unordered_map<char, int>> arr(100000);
        for (int i = 0 ; i < res.length() ; i++) {
            if (i > 0 && res[i] != res[i - 1]) index++;
            arr[index][res[i]]++; 
        }
        string convert = "";
        for (unordered_map<char, int> map : arr)  {
            for(auto i : map) {
                cout << i.first << " :" << i.second << endl;
                convert += (to_string(i.second) + i.first);
            }
        }
        return recursive(iter + 1, max, convert);
    }
    string countAndSay(int n) {
        return recursive(1, n, "1");
    }
};