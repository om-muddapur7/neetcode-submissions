class Solution {
public:

    vector<vector<int>> directions = {{-1, 0}, {1, 0},
                                      {0, -1}, {0, 1}};

    int dfs(int r, int c, vector<vector<int>>& matrix, int prev){
        int rows = matrix.size();
        int cols = matrix[0].size();

        if(r<0 || r>=rows || c<0 || c>=cols || matrix[r][c] <= prev ){
            return 0;
        }

        int res = 1;
        for(auto d: directions){
            res = max(res, 1 + dfs(r+d[0], c+d[1], matrix, matrix[r][c]));
        }

        return res;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int lip = 0;

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                lip = max(lip, dfs(i, j, matrix, INT_MIN));
            }
        }

        return lip;
    }
};
