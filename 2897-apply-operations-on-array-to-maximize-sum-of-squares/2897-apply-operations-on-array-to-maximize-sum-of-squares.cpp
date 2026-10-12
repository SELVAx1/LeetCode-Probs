class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> sbcnt(31, 0);
        const long long MOD = 1e9 + 7;
        for(int i = 0; i < nums.size(); i++){
            for(int b = 0; b <= 30; b++){
                if((nums[i] >> b) & 1 == 1){
                    sbcnt[b]++;
                }
            }
        }
        long long ans = 0;
        for(int i = 0; i < k; i++){
            long long curr = 0;
            for(int b = 0; b <= 30; b++){
                if(sbcnt[b] > 0){
                    curr += (1 << b);
                    sbcnt[b]--;
                }
            }
            ans = (ans + ((curr*curr) % MOD));
        }
        return ans % MOD;
    }
};