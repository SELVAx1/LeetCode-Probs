class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1 ) return s;
        vector<vector<char>>rows(numRows);
        int idx=0,dir=1;
        for(int i=0;i<s.size();i++){
            rows[idx].push_back(s[i]);
            if(idx==0){
                dir=1;
            }else if(idx==numRows-1){
                dir=-1;
            }
            idx+=dir;
        }
        string ans="";
        for(auto &vec:rows){
            for(auto ch:vec){
                ans+=ch;
            }
        }
        return ans;
    }
};