class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int freshCnt = 0;
        queue<pair<pair<int, int>, int>> q;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                } else {
                    vis[i][j] = 0;
                }

                if(grid[i][j] == 1) freshCnt++;
            }
        }

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        int maxTime = 0;
        int cnt = 0;

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();

            maxTime = max(maxTime, time);

            for(int i=0; i<4; i++){
                int r = row + dr[i];
                int c = col + dc[i];

                if(r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1 && vis[r][c] == 0) {
                    vis[r][c] = 2;
                    cnt++;
                    q.push({{r, c}, time+1});
                }
            }
        }

        if(freshCnt != cnt) return -1;
        return maxTime;
    }
};
