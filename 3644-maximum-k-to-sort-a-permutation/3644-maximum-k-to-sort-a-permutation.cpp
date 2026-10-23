class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int k = -1;
        if(nums[0] != 0){
            return 0;
        }
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != i){
                k &= nums[i];
            }
        }
        return max(k, 0);
    }
};