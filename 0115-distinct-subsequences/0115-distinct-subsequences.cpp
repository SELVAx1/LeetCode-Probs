class Solution {
private:
    int cntSeq(int i, int j, string& s, string& t, vector<vector<int>>& dp){
        if(j == 0){
            return 1;
        }
        if(i == 0){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i-1] == t[j-1]){
            return dp[i][j] = cntSeq(i-1, j, s, t, dp) + cntSeq(i-1, j-1, s, t, dp);        // matching ->take , nottake
        }else{
            return dp[i][j] = cntSeq(i-1, j, s, t, dp);             // not matching 
        }
    }
public:
    int numDistinct(string s, string t) {
        int N = s.size(), M = t.size();
        vector<vector<int>> dp(N+1, vector<int> (M+1, -1));
        return cntSeq(N, M, s, t, dp);
    }
};