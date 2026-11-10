class Solution {
public:
    int climbStairs(int N, vector<int>& costs) {
        vector<int> dp(N+1, 0);
        for(int i = 1; i <= N; i++){
            int mincost = INT_MAX;
            for(int j = max(0, i - 3); j < i; j++){
                mincost = min(mincost, dp[j] + costs[i-1] + (i - j) * (i - j));
            }
            dp[i] = mincost;
        }
        return dp[N];
    }
};