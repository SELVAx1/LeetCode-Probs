class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxval = *max_element(nums.begin(), nums.end());
        vector<int> tot(maxval+1, 0), dp(maxval+1, 0);
        
        for(int i = 0; i < nums.size(); i++){
            tot[nums[i]] += nums[i];
        }

        dp[0] = tot[0];
        dp[1] = max(tot[0], tot[1]);
        for(int i = 2; i <= maxval; i++){
            dp[i] = max(tot[i]+dp[i-2], dp[i-1]);
        }
        return dp[maxval];
    }
};