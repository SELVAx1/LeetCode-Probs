class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int ans = 0;
        int N = nums.size();
        int flg = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0) {
                flg = 1;
            }
            ans ^= nums[i];
        }
        if(ans != 0) return N;
        if(flg) return N-1;         //if entire arr xor = 0 where there is non-zero el
        return 0;
    }
};