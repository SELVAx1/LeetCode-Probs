class Solution {
public:
    int diff[5] = {0, 1, 0, -1, 0};
    int closedIsland(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        vector<vector<bool>> vis(R, vector<bool> (C, 0));

        function<void(int, int)> dfs = [&](int row, int col){
            // grid[row][col] = 1;
            vis[row][col] = 1;
            for(int i = 0; i < 4; i++){
                int adjr = row + diff[i];
                int adjc = col + diff[i+1];
                if(adjr >= 0 && adjc >= 0 && adjr < R && adjc < C && grid[adjr][adjc] == 0 && !vis[adjr][adjc]){
                    dfs(adjr, adjc);
                }
            }
        };

        for(int row = 0; row < R; row++){
            if(grid[row][0] == 0 && !vis[row][0]) dfs(row, 0);
            if(grid[row][C-1] == 0 && !vis[row][C-1]) dfs(row, C-1);
        }
        for(int col = 0; col < C; col++){
            if(grid[0][col] == 0 && !vis[0][col]) dfs(0, col);
            if(grid[R-1][col] == 0 && !vis[R-1][col]) dfs(R-1, col);
        }

        int ans = 0;
        for(int row = 0; row < R; row++){
            for(int col = 0; col < C; col++){
                if(grid[row][col] == 0 && !vis[row][col]){
                    ans++;
                    dfs(row, col);
                }
            }
        }
        return ans;
    }
};