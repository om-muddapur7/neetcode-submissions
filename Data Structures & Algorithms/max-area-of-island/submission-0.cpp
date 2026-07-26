class Solution {
public:

    int bfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis){
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        int res = 1;
        queue<pair<int,int>> q;
        q.push({row,col});

        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};


        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                        res++;
                    }
            }
        }
        return res;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        int area = 0;
        vector<vector<int>>vis(n, vector<int>(m, 0));

        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(!vis[row][col] && grid[row][col] == 1){
                    area = max(area, bfs(row, col, grid, vis)) ;
                }
            }
        }
        return area;
    }
};
