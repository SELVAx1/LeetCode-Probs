class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int lt = 0, rt = 0;
        int maxlen = 0;
        unordered_map<int,int> mpp;
        while(rt < nums.size()){
            if(mpp[nums[rt]] < k){
                mpp[nums[rt]]++;
                maxlen = max(maxlen, rt-lt+1);
            }else{
                while(mpp[nums[rt]] >= k){
                    mpp[nums[lt]]--;
                    lt++;
                }
                mpp[nums[rt]]++;
            }
            rt++;
        }
        return maxlen;
    }
};