using ll = long long;
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        ll sum = 0, ans = 0;
        auto add = [&](int i){
            sum += nums[i];
            ++mpp[nums[i]];
        };
        auto del = [&](int i){
            sum -= nums[i];
            if(--mpp[nums[i]] == 0) mpp.erase(nums[i]);
        };
        for(int i = 0; i < k; i++){
            add(i);
        }
        if(mpp.size() == k) ans = sum;
        for(int i = k; i < nums.size(); i++){
            add(i);
            del(i-k);
            if(mpp.size() == k){
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};