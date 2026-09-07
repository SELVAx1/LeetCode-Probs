class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9+7;
        array<int, 26> seen;
        seen.fill(-1);
        int N = s.size();
        vector<int> dp(N+1, 0);
        dp[0] = 1;                  // empty string is subseq
        for(int i = 0; i < N; i++){
            int ind = s[i] - 'a';
            dp[i+1] = (dp[i] * 2) % MOD;
            if(seen[ind] >= 0){
                dp[i+1] -= dp[seen[ind]];                       // 2*curr - cnt bfre lst time this char appeared
                dp[i+1] = (dp[i+1]+MOD) % MOD;        
            }
            seen[ind] = i;
        }
        return (dp[N] - 1 + MOD) % MOD;                       // delete empty string 
    }
};