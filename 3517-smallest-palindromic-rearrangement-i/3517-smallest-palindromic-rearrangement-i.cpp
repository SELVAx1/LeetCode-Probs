class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>vec(26,0);
        if(s.size()==1) return s;
        for(int i=0;i<s.size();i++){
            vec[s[i]-'a']++;
        }
        string frnt="",back="";
        char mid='#';
        for(int i=0;i<26;i++){
            char ch = i+'a';
            while(vec[i] >= 2){
                frnt.push_back(ch);
                back.insert(0,1,ch);
                vec[i] -= 2;
            }
            if(vec[i] == 1){
                mid = ch ;
            }
        }
        if(mid!='#') frnt.push_back(mid);
        return frnt+back;
    }
};