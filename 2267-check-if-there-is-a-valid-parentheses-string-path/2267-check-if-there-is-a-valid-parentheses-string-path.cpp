class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int R = grid.size(), C = grid[0].size();
        vector<vector<unordered_set<int>>> dp(R, vector<unordered_set<int>>(C));
        if(grid[0][0] == ')') return 0;
        dp[0][0].insert(1);
        for(int row = 1; row < R; row++){
            if(dp[row-1][0].empty()) continue;
            int x = *dp[row-1][0].begin();
            int diff = grid[row][0] == '(' ? 1 : -1;
            if(x+diff >= 0){
                dp[row][0].insert(x+diff);
            }
        }
        for(int col = 1; col < C; col++){
            if(dp[0][col-1].empty()) continue;
            int x = *dp[0][col-1].begin();
            int diff = grid[0][col] == '(' ? 1 : -1;
            if(x+diff >= 0){
                dp[0][col].insert(x+diff);
            }
        }
        for(int row = 1; row < R; row++){
            for(int col = 1; col < C; col++){
                int diff = grid[row][col] == '(' ? 1 : -1;
                for(int x : dp[row][col-1]){
                    if(x+diff >= 0){
                        dp[row][col].insert(x+diff);
                    }
                }
                for(int x : dp[row-1][col]){
                    if(x+diff >= 0){
                        dp[row][col].insert(x+diff);
                    }
                }
            }
        }
        return dp[R-1][C-1].contains(0);
    }
    // curr = left + top;
    // if -1 comes , [stop] as ) comes
};