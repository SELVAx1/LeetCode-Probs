class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> res(matrix[0].size(), vector<int>(matrix.size(), 0));
        for(int row = 0; row < matrix.size(); row++){
            for(int col = 0; col < matrix[0].size(); col++){
                res[col][row] = matrix[row][col];
            }
        }
        return res;
    }
};