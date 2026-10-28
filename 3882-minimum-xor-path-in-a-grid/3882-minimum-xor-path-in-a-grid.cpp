class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        vector<vector<vector<bool>>> dp(R, vector<vector<bool>>(C, vector<bool>(1024, false)));
        
        dp[0][0][grid[0][0]] = true;

        for(int row = 0; row < R; row++){
            for(int col = 0; col < C; col++){
                for(int x = 0; x < 1024; x++){
                    if(!dp[row][col][x]){
                        continue;
                    }
                    if(row+1 < R){
                        dp[row+1][col][x^grid[row+1][col]] = true;
                    }
                    if(col+1 < C){
                        dp[row][col+1][x^grid[row][col+1]] = true;
                    }
                }
            }
        }
        for(int x = 0; x < 1024; x++){
            if(dp[R-1][C-1][x]) return x;
        }
        return 0;
    }
};