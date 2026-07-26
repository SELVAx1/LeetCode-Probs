class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int N=nums.size();
        int pro1=nums[0]*nums[1]*nums[N-1];
        int pro2=nums[N-1]*nums[N-2]*nums[N-3];
        return max(pro1,pro2);
    }
};