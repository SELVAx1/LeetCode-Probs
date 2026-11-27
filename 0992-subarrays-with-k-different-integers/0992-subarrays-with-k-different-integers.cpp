class Solution {
public:
    int solve(vector<int>& nums, int k){
        int lt = 0, N = nums.size();
        unordered_map<int, int> mpp;
        int ans = 0;
        for(int rt = 0; rt < N; rt++){
            mpp[nums[rt]]++;
            while(mpp.size() > k){
                if(--mpp[nums[lt]] == 0){
                    mpp.erase(nums[lt]);
                }
                lt++;
            }
            ans += rt - lt + 1;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int atmostk = solve(nums, k);
        int atmostkneg1 = solve(nums, k-1);
        return (atmostk - atmostkneg1);
    }
};