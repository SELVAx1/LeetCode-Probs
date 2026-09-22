class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> mpp;
        int N = nums.size();
        for(int i = 0; i < N; i++){
            mpp[nums[i]] = i;
        }
        for(int i = 0; i < operations.size(); i++){
            int pos = mpp[operations[i][0]];
            nums[pos] = operations[i][1];
            mpp.erase(operations[i][0]);
            mpp[operations[i][1]] = pos;
        }
        return nums;
    }
};