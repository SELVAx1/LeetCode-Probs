class Solution {
public:
    int longestValidParentheses(string s) {
        int lt = 0, rt = 0;
        int N = s.size();
        int ans = 0;
        int oc = 0, cc = 0;
        while(rt < N){
            if(s[rt] == '(') oc++;
            else cc++;
            while(cc > oc){
                if(s[lt] == '(') oc--;
                else cc--;
                lt++;
            }
            if(oc == cc) ans = max(ans, rt-lt+1);
            rt++;
        }
        lt = N-1, rt = N-1;
        oc = 0, cc = 0;
        while(lt >= 0){
            if(s[lt] == '(') oc++;
            else cc++;
            while(oc > cc){
                if(s[rt] == '(') oc--;
                else cc--;
                rt--;
            }
            if(oc == cc) ans = max(ans, rt-lt+1);
            lt--;
        }
        return ans;
    }
};