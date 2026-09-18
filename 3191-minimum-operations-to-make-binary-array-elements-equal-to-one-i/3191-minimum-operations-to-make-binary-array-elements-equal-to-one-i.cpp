class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt = 0;
        int N =nums.size();
        for(int i = 0; i < N-2; i++){
            if(nums[i] == 0){
                nums[i] ^= 1;
                nums[i+1] ^= 1;
                nums[i+2] ^= 1;
                cnt++;
            }
        }
        return (nums[N-1] != 0 && nums[N-2] != 0) ? cnt : -1;
    }
};