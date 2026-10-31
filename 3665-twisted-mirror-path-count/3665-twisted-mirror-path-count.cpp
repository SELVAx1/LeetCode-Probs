class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        const int MOD = 1e9+7;

        vector<vector<vector<int>>> dp(R, vector<vector<int>> (C, {-1, -1}));
        function<int(int, int, int)> dfs = [&](int row, int col, int dir){
            if(row >= R || col >= C) return 0;
            if(row == R-1 && col == C-1) return 1;
            if(dp[row][col][dir] != -1) return dp[row][col][dir];

            if(grid[row][col] == 1){
                if(dir == 0){
                    dp[row][col][dir] = dfs(row+1, col, 1);
                }else{
                    dp[row][col][dir] = dfs(row, col+1, 0);
                }
            }else{
                dp[row][col][dir] = (dfs(row, col+1, 0) + dfs(row+1, col, 1)) % MOD;
            }
            return (dp[row][col][dir]) % MOD;
        };

        return dfs(0, 0, 0);
    }
};