class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0;
        for(char ch='A';ch<='Z';ch++){
            int i=0,diff=0;
            for(int j=0;j<s.size();j++){
                if(s[j]!=ch){
                    diff++;
                }
                while(diff>k){
                    if(s[i]!=ch){
                        diff--;
                    }
                    i++;
                }
                ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};