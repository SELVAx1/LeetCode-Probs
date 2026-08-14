class Solution {
public:
    int maximumLengthSubstring(string s) {
        int lt=0,rt=0,ans=0;
        vector<int>freq(26,0);
        while(rt<s.size()){
            char ch=s[rt++];
            freq[ch-'a']++;
            while(freq[ch-'a']==3){
                freq[s[lt++]-'a']--;
            }
            ans=max(ans,rt-lt);
        }
        return ans;
    }
};