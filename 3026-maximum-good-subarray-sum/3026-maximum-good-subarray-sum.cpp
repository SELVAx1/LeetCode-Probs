using ll = long long;
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int N = nums.size();
        map<int, int> mpp;          // store index
        vector<ll> pref(N);
        ll tot = 0;
        for(int i = 0; i < N; i++){
            tot += nums[i];
            pref[i] = tot;
        }
        ll ans = LLONG_MIN;
        mpp[nums[0]] = 0;
        for(int i = 1; i < N; i++){
            ll tar1 = nums[i] + k;
            ll tar2 = nums[i] - k;
            if(mpp.find(tar1) != mpp.end()){
                ll curr = pref[i] - pref[mpp[tar1]] + nums[mpp[tar1]];    
                ans = max(ans, curr);
            }
            if(mpp.find(tar2) != mpp.end()){
                ll curr = pref[i] - pref[mpp[tar2]] + nums[mpp[tar2]];
                ans = max(ans, curr);
            }
            if(mpp.find(nums[i]) != mpp.end()){
                if(pref[i] > pref[mpp[nums[i]]]){
                    continue;
                }
            }
            mpp[nums[i]] = i;
        }
        return ans == LLONG_MIN ? 0 : ans;
    }
};