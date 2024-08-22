class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> row(9), col(9), box(9);
        for(int i = 0 ; i < 9 ; i++){
            for(int j = 0 ; j < 9 ; j++){
                int boxIdx = i / 3 * 3 + j / 3;
                if(board[i][j] == '.') continue;
                if(col[j].find(board[i][j]) != col[j].end() ||
                    row[i].find(board[i][j]) != col[i].end() || 
                    box[boxIdx].find(board[i][j]) != box[boxIdx].end() 
                ) return false;

                col[j].insert(board[i][j]);
                row[i].insert(board[i][j]);
                box[boxIdx].insert(board[i][j]);

            }
        }
        return true;
    }
};
