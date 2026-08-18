class Solution {
public:

    int dfs(int i, int j, vector<vector<bool>>& vis,
            vector<vector<int>>& grid, int n, int m) {

        if(i < 0 || i >= n || j < 0 || j >= m ||
           vis[i][j] || grid[i][j] != 1) {
            return 0;
        }

        vis[i][j] = true;

        int cnt = 1;

        cnt += dfs(i-1, j, vis, grid, n, m);
        cnt += dfs(i+1, j, vis, grid, n, m);
        cnt += dfs(i, j-1, vis, grid, n, m);
        cnt += dfs(i, j+1, vis, grid, n, m);

        return cnt;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int maxi = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 1 && !vis[i][j]) {

                    int area = dfs(i, j, vis, grid, n, m);

                    maxi = max(maxi, area);
                }
            }
        }

        return maxi;
    }
};