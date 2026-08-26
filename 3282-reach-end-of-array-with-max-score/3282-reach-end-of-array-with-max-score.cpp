class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long ans = 0;
        int N = nums.size();
        long long prev = nums[0];
        int prevind = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > prev){
                ans += (i-prevind) * prev;
                prev = nums[i];
                prevind = i;
            }
        }
        if(prevind != N-1){
            ans += (N-1-prevind) * prev;
        }
        return ans;
    }
};