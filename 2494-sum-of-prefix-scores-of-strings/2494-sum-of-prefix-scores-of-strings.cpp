class TrieNode {
public:
    TrieNode* children[26]; 
    int count; 
    
    TrieNode() {
        for(int i = 0 ; i < 26 ; i++) {
            children[i] = nullptr;
        }
        count = 0;
    }
    void insert(string& s) {
        TrieNode* curr = this;
        for(char c : s) {
            int index = c - 'a';
            if(curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
            curr->count++;
        }
    }
    int getPrefixScore(string& s) {
        TrieNode* curr = this;
        int score = 0;
        for(char c : s) {
            int index = c - 'a';
            curr = curr->children[index];
            score += curr->count;
        }
        return score;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(string& word : words) {
            root->insert(word);
        }
        vector<int> ans;
        for(string& word : words) {
            int score = root->getPrefixScore(word);
            ans.push_back(score);
        }
        
        return ans;
    }
};
