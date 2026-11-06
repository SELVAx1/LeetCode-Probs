class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int R = str1.size();
        int C = str2.size();
        string res = "";
        vector<vector<int>> dp(R+1, vector<int> (C+1, 0));

        function<void(int, int, string)> backTrack = [&](int row, int col, string curr){
            if(row == 0 || col == 0){
                while(row > 0){
                    curr += str1[row-1];
                    row--;
                }
                while(col > 0){
                    curr += str2[col-1];
                    col--;
                }
                reverse(curr.begin(), curr.end());
                res = curr;
                return ;
            }
            if(str1[row-1] == str2[col-1]){
                backTrack(row-1, col-1, curr + str1[row-1]);
            }else if(dp[row-1][col] >= dp[row][col-1]){
                backTrack(row-1, col, curr + str1[row-1]);
            }else{
                backTrack(row, col-1, curr + str2[col-1]);
            }
        };
        
        for(int row = 1; row <= R; row++){
            for(int col = 1; col <= C; col++){
                if(str1[row-1] == str2[col-1]){
                    dp[row][col] = dp[row-1][col-1] + 1;
                }else{
                    dp[row][col] = max(dp[row-1][col], dp[row][col-1]);
                }
            }
        }
        backTrack(R, C, "");
        return res;
    }
};