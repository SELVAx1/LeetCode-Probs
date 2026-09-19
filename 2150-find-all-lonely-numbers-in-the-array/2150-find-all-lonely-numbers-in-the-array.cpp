class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        if(N == 1) return nums;
        vector<int> ans;
        if(nums[0]+1 != nums[1] && nums[0]-1 != nums[1] && nums[0] != nums[1]){
            ans.push_back(nums[0]);
        }
        for(int i = 1; i < nums.size()-1; i++){
            if(nums[i]+1 != nums[i+1] && nums[i]-1 != nums[i-1] && nums[i] != nums[i-1] && nums[i] != nums[i+1]){
                ans.push_back(nums[i]);
            }
        }
        if(nums[N-2]+1 != nums[N-1] && nums[N-2]-1 != nums[N-1] && nums[N-2] != nums[N-1]){
            ans.push_back(nums[N-1]);
        }
        return ans;
    }
};