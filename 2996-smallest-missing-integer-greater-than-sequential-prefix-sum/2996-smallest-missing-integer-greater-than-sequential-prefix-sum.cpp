class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int pref = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1] + 1) pref += nums[i];
            else break;
        }
        unordered_set<int> myset(nums.begin(), nums.end());
        while(myset.count(pref)) pref++;
        return pref;
    }
};