class Solution {
public:
    long long minimumSteps(string s) {
        long long cnt = 0;
        int blackballs = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0'){
                cnt += blackballs;          // swap prev cnt blackballs
            }else{
                blackballs++;               
            }
        }
        return cnt;
    }
};