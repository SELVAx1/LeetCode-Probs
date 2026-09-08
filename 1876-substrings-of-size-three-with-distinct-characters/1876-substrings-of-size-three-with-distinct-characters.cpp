class Solution {
public:
    int countGoodSubstrings(string s) {
       int N = s.size();
       if(N < 3) return 0;
       int cnt = 0;
       for(int i = 0; i <= N-3; i++){
            vector<int> freq(26, 0);
            int flg = 0;
            for(int k = i; k < i+3; k++){
                if(freq[s[k]-'a'] > 0){
                    flg = 1;
                    break;
                }
                freq[s[k]-'a']++;
            }
            if(!flg){
                cnt++;
            }
       } 
       return cnt;
    }
};