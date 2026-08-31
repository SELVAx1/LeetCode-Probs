class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, int> mpp;
        mpp[nums[0]] = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i-1]){
                mpp[nums[i]]++;
            }
        }
        int cnt = 0;
        for(auto x : mpp){
            if(x.second == 1)
                cnt++;
        }
        return cnt;
    }
};