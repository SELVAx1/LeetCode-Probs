class Solution {
private:
    bool isValid(int row, int col, vector<vector<int>>& grid){
        vector<bool> range(10, 0);
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                int num = grid[row+i][col+j];
                if(num < 1 || num > 9 || range[num])
                    return false;
                range[num] = true;
            }
        }
        int sum = grid[row][col] + grid[row][col+1] + grid[row][col+2];
        for(int i = 0; i < 3; i++){
            if(sum != grid[row+i][col] + grid[row+i][col+1] + grid[row+i][col+2])
                return false;
        }
        for(int j = 0; j < 3; j++){
            if(sum != grid[row][col+j] + grid[row+1][col+j] + grid[row+2][col+j])
                return false;
        }
        if(sum != grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2])
            return false;
        if(sum != grid[row+2][col] + grid[row+1][col+1] + grid[row][col+2])
            return false;
        return true;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        if(R < 3 && C < 3) return 0;
        int cnt = 0;
        for(int row = 0; row <= R-3; row++){
            for(int col = 0; col <= C-3; col++){
                if(isValid(row, col, grid))
                    cnt++;
            }
        } 
        return cnt;
    }
};