class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int lt = INT_MAX, rt = INT_MIN, ltind, rtind;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < lt){
                lt = nums[i];
                ltind = i;
            }
            if(nums[i] > rt){
                rt = nums[i];
                rtind = i;
            }
        }
        if(ltind > rtind){
            swap(ltind, rtind);
        }
        int N = nums.size();
        int res = (ltind + 1) + (N - rtind);
        return min({res, N-ltind, rtind+1});
    }
};