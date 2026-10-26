class Solution {
public:
    int diff[5] = {0, -1, 0, 1, 0};
    long sum = 0;
    void dfs(vector<vector<int>>& grid, int R, int C, int row, int col) {
        sum += grid[row][col];
        grid[row][col] = -1;
        for(int num = 0; num < 4; num++){
            int adjr = row + diff[num];
            int adjc = col + diff[num + 1];
            if(adjr >= 0 && adjc >= 0 && adjr < R && adjc < C && grid[adjr][adjc] > 0){
                dfs(grid, R, C, adjr, adjc);
            }
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int R = grid.size();
        int C = grid[0].size();
        int cnt = 0;
        for(int row = 0; row < R; row++){
            for(int col = 0; col < C; col++){
                if(grid[row][col] > 0){
                    sum = 0;
                    dfs(grid, R, C, row, col);
                    if (long(sum % k) == 0)
                        cnt++;
                }
            }
        }
        return cnt;
    }
};