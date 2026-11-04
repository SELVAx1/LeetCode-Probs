class Solution {
public:
    int findPaths(int R, int C, int maxMove, int startRow, int startColumn) {
        int dir[5] = {0, 1, 0, -1, 0};
        int MOD = 1e9+7;
        int dp[51][51][51];
        memset(dp, -1, sizeof(dp));

        function<int(int, int, int)> boundCount = [&](int move, int row, int col){
            if(row >= R || row < 0 || col >= C || col <0) return 1;
            if(move == 0) return 0;
            if(dp[row][col][move] != -1) return dp[row][col][move];
            long long paths = 0;
            for(int i = 0; i < 4; i++){
                int adjr = row + dir[i];
                int adjc = col + dir[i+1];
                paths = (paths + boundCount(move-1, adjr, adjc)) % MOD;
            }
            dp[row][col][move] = paths;
            return (int)paths;
        };

        return boundCount(maxMove, startRow, startColumn);
    }
};