class Solution {
public:
    string minWindow(string s, string t) {
        int N = s.size();
        int M = t.size();
        unordered_map<char,int> mpp;
        for(int i=0; i<M; i++){
            mpp[t[i]]++;
        }
        int lt = 0, rt = 0;
        int cnt = 0;
        int minlen = INT_MAX, stind = -1;
        while(rt < N){
            if(mpp[s[rt]] > 0){
                cnt++;
            }
            mpp[s[rt]]--;
            while(cnt == M){
                if(rt-lt+1 < minlen){
                    minlen = rt-lt+1;
                    stind = lt;
                }
                mpp[s[lt]]++;
                if(mpp[s[lt]] > 0) cnt--;
                lt++;
            }
            rt++;
        }
        return stind == -1 ? "" : s.substr(stind, minlen);
    }
};