class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        vector<int> rowflg(R, 0);
        vector<int> colflg(C, 0);

        for(int row = 0; row < R; row++) {
            int cnt = 0;
            for(int col = 0; col < C; col++) {
                if(grid[row][col] == 1) {
                    cnt++;
                    colflg[col] += 1;
                }
            }
            rowflg[row] = cnt;
        }

        int commcnt = 0;
        for(int row = 0; row < R; row++) {
            for(int col = 0; col < C; col++) {
                if(grid[row][col] == 1) {
                    if(rowflg[row] > 1 || colflg[col] > 1)
                        commcnt++;
                }
            }
        }
        return commcnt;
    }
};