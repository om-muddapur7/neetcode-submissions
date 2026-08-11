class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));

        helper(board, 0, n, res);

        return res;
    }

    void helper(vector<string>& board, int row, int n, vector<vector<string>>& res){
        if(row == n){
            res.push_back(board);
            return;
        }

        for(int j=0; j<n; j++){
            if(isSafe(board, row, j, n)){
                board[row][j] = 'Q';
                helper(board, row+1, n, res);
                board[row][j] = '.';
            }
        }
    }

    bool isSafe(vector<string>& board, int row, int col, int n){
        for(int j=0; j<n; j++){
            if(board[row][j] == 'Q') return false;
        }

        for(int i=0; i<n; i++){
            if(board[i][col] == 'Q') return false;
        }

        for(int i=row, j=col; i>=0 && j>=0; i--, j--){
            if(board[i][j] == 'Q') return false;
        }

        for(int i=row, j=col; i>=0 && j<n; i--, j++){
            if(board[i][j] == 'Q') return false;
        }

        return true;
    }

};
