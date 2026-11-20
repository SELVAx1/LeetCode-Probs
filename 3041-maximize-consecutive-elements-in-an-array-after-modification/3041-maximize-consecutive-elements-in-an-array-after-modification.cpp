class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        ranges::sort(nums);
        unordered_map<int, int> dp;         // store cnt
        int ans = 1;
        for(auto x : nums){                  // 2 choice : inc or not
            int up = dp[x] + 1;             // if inc, curr + 1 is cnt
            int stay = dp[x-1] + 1;         // else prev + 1

            dp[x+1] = max(up, dp[x+1]);     // already cal.cnt or updated
            dp[x] = max(stay, dp[x]);
            ans = max({ans, up, stay});
        }
        return ans;
    }
};