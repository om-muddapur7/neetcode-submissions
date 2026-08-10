class Solution {
public:
    
    bool dfs(vector<vector<char>>& board, string word, int r, int c, int idx){

        if(idx == word.size()) return true;

        if(r<0 || r>=board.size() || c<0 || c>=board[0].size() || board[r][c] != word[idx]){
            return false;
        }

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        char ch = board[r][c];
        board[r][c] = '#';

        for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(dfs(board, word, nr, nc, idx+1)){
                board[r][c] = ch;
                return true;
            }
        }

        board[r][c] = ch;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int i=0;
        string res;

        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == word[0]) {
                    if(dfs(board, word, i, j, 0)) return true;
                }
            }
        }

        return false;
    }
};
