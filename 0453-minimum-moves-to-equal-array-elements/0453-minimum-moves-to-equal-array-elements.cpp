class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min = *min_element(nums.begin(),nums.end());
        int sum = 0;
        for(auto x : nums){
            sum += (x-min);
        }
        return sum;
    }
};