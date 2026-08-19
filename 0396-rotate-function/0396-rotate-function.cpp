class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long tot = 0;
        long ans = 0;
        for(int i = 0; i < nums.size(); i++){
            tot += nums[i];
            ans += (nums[i]*i);
        }
        int N = nums.size();
        int flg = nums.size()-1;
        long res = ans;
        while(flg){
            long curr = ans - (nums[flg]*(N-1)) + (tot-nums[flg]);
            res = max(res, curr);
            ans = curr;
            flg--;
        }
        return (int)res;
    }
};