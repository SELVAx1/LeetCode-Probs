class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> mpp;
        const int MOD = 60;
        int cnt = 0;
        for(int i = 0; i < time.size(); i++){
            int rem = time[i] % MOD;
            int comp = (MOD - rem) % MOD;
            if(mpp.count(comp)){
                cnt += mpp[comp];
            }
            mpp[rem]++;
        }
        return cnt;
    }
};