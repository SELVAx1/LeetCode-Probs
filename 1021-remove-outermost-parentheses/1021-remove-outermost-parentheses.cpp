class Solution {
public:
    string removeOuterParentheses(string s) {
        int i=0;string res="";
        int c=0;
        while(i<s.size()){
            if(s[i]=='(' && c++>0){
                res+=s[i];
            }
            if(s[i]==')' && c-->1){
                res+=s[i];
            }
        i++;
        }
        return res;
    }
};