class Solution {
public:
    int numSub(string s) {
        const int MOD = 1e9+7;
        int cnt = 0, ans = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1'){
                cnt++;
            }else{
                ans = (ans + (1LL*cnt*(cnt+1))/2) % MOD;                      //combination n*(n+1) / 2 
                cnt = 0;
            }
        }
        if(cnt){
            ans += (cnt*(cnt+1))/2;  
        }
        return ans%MOD;
    }
};