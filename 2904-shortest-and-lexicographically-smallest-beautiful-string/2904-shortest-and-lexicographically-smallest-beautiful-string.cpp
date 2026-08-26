class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int N = s.size();
        int cnt = 0, lt = 0, rt = 0;
        int minlen = INT_MAX, stind = -1;
        vector<int> mpp(2, 0);
        mpp[1] = k;
        while(rt < N){
            if(mpp[s[rt]-'0'] > 0){
                cnt++;
            }
            mpp[s[rt]-'0']--;
            while(cnt == k){
                int len = rt-lt+1;
                if(len < minlen || (len == minlen && s.substr(lt, len) < s.substr(stind, minlen))){
                    minlen = len;
                    stind = lt;
                }
                mpp[s[lt]-'0']++;
                if(mpp[s[lt]-'0'] > 0){
                    cnt--;
                }
                lt++;
            }
            rt++;
        }
        return minlen == INT_MAX ? "" : s.substr(stind, minlen);
    }
};