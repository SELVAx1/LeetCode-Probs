class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int> list;
        for(int i = 0; i < nums.size(); i++){
            auto it = upper_bound(list.begin(), list.end(), nums[i]);
            if(it == list.end()){
                list.push_back(nums[i]);
            }else{
                *it = nums[i];
            }
        }
        return nums.size() - list.size();
    }
};