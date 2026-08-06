class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind = -1, N = nums.size();
        for(int i = N-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                ind = i;
                break;
            }
        }
        // if(ind != -1) cout<<nums[ind];
        for(int i = N-1; i >= 0 && ind != -1; i--){
            if(nums[i] > nums[ind]){
                swap(nums[i], nums[ind]);
                break;
            }
        }
        reverse(nums.begin() + ind + 1, nums.end());
    }
};