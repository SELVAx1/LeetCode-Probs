class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        ranges::sort(nums);
        int N = nums.size();
        int med = (N % 2 == 0) ? max(nums[N/2], nums[N/2 - 1]) : nums[N/2];
        long long op = abs(k - med);
        if(k < med){
            for(int i = 0; i < N/2; i++){
                if(nums[i] > k){
                    op += abs(k - nums[i]);
                }
            }
        }else{
            for(int i = N/2+1; i < N; i++){
                if(nums[i] < k){
                    op += abs(k - nums[i]);
                }
            }
        }
        return op;
    }
};