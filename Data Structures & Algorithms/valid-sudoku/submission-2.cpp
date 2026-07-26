class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //row
         for(int i = 0; i < 9; i++){
            set<char> s;
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                if(s.count(board[i][j])) return false;
                s.insert(board[i][j]);
            }
        }

        //col
        for(int j = 0; j < 9; j++){
            set<char> s;
            for(int i = 0; i < 9; i++){
                if(board[i][j] == '.') continue;
                if(s.count(board[i][j])) return false;
                s.insert(board[i][j]);
            }
        }

        //sq
        for(int row = 0; row < 9; row += 3){
            for(int col = 0; col < 9; col += 3){

                set<char> s;

                // scan 3x3 box
                for(int i = row; i < row + 3; i++){
                    for(int j = col; j < col + 3; j++){

                        char val = board[i][j];
                        if(val == '.') continue;

                        if(s.count(val)) return false;
                        s.insert(val);
                    }
                }
            }
        }

        return true;
    }
};
