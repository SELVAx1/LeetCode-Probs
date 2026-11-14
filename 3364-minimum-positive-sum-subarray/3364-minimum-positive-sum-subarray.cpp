class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int N = nums.size();
        int ans = INT_MAX;
        for(int i = 0; i < N; i++){
            int sum = 0;
            for(int j = i; j < N; j++){
                sum += nums[j];
                int len = j - i + 1;
                if(len >= l && len <= r && sum > 0){
                    ans = min(ans, sum);
                }
                if(len > r) break;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};