class Solution {
    int diff[5] = {0, 1, 0, -1, 0};
private:
    void dfs(int row, int col, int R, int C, vector<vector<int>>& vis, vector<vector<int>>& grid){
        vis[row][col] = 1;
        for(int i = 0; i < 4; i++){
            int adjr = row + diff[i];
            int adjc = col + diff[i+1];
            if(adjr >= 0 && adjr < R && adjc >= 0 && adjc < C && grid[adjr][adjc] == 1 && !vis[adjr][adjc]){
                dfs(adjr, adjc, R, C, vis, grid);
            }
        }
    }
    int countIsland(int R, int C, vector<vector<int>> vis, vector<vector<int>>& grid){
        int island = 0;
        for(int row = 0; row < R; row++){
            for(int col = 0; col < C; col++){
                if(grid[row][col] == 1 && !vis[row][col]){
                    island++;
                    if(island == 2) return 2;
                    dfs(row, col, R, C, vis, grid);
                }
            }
        }
        return island;
    }
public:
    int minDays(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        vector<vector<int>> vis(R, vector<int>(C, 0));              
        
        int ans = countIsland(R, C, vis, grid);                     // zero case
        if(ans != 1) return 0;
        
        for(int row = 0; row < R; row++){                           // one case
            for(int col = 0; col < C; col++){
                if(grid[row][col] == 1){
                    grid[row][col] = 0;
                    int ans = countIsland(R, C, vis, grid);
                    if(ans != 1) return 1;
                    grid[row][col] = 1;
                }
            }
        }
        return 2;
    }
};