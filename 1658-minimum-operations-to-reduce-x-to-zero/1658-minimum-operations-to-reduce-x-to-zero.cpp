class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int tot=accumulate(nums.begin(),nums.end(),0);
        int rem=tot-x;
        if(rem==0) return nums.size();
        int currsum=0,res=-1;
        unordered_map<int,int>mpp;
        mpp[0]=-1;
        for(int i=0;i<nums.size();i++){
            currsum+=nums[i];
            int diff=currsum-rem;
            if(mpp.find(diff)!=mpp.end()){
                res=max(res,i-mpp[diff]);
            }
            if(mpp.find(currsum)==mpp.end()){
                mpp[currsum]=i;
            }
        }
        return res==-1 ? -1 : nums.size()-res;
    }
};