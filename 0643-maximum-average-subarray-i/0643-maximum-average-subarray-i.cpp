class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0, ans = INT_MIN;
        int lt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i >= k){
                sum -= nums[lt];
                lt++;
            }
            sum += nums[i];
            if(i >= k-1){
                ans = max(ans, sum/k);
            }
        }
        return ans;
    }
};