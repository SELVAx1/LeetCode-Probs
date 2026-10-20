class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        map<int, int> mpp;
        for(int x : nums){
            mpp[x]++;
        }

        int N = nums.size();
        if(N % k != 0) return 0;

        int grp = N/k;
        for(auto x : mpp){
            if(x.second > grp){
                return 0;
            }
        }
        return 1;
    }
};