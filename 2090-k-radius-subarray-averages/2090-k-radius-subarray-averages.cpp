using ll = long long;
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int N = nums.size();
        if(k == 0){
            return nums;
        }
        vector<int> ans(N, -1);
        vector<ll> pref(N);
        pref[0] = nums[0];
        ll tot = nums[0];
        for(int i = 1; i < N; i++){
            tot += nums[i];
            pref[i] = tot;
        }
        for(int i = k; i < N-k; i++){
            ans[i] = (i-k-1 >= 0) ? (pref[i+k]-pref[i-k-1])/(k*2+1) : (pref[i+k])/(k*2+1) ;
        }
        return ans;
    }
};