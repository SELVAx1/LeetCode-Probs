class Solution {
    set<string> myset;
private:
    void dfs(string& s, int idx, int bal, string& valstr){
        if(bal < 0){
            return ;
        }
        if(idx == s.size()){
            if(bal == 0){
                myset.insert(valstr);
            }
            return ;
        }
        char ch = s[idx];
        if(ch != '(' && ch != ')'){
            valstr.push_back(ch);
            dfs(s, idx+1, bal, valstr);
            valstr.pop_back();
        }else{
            if(ch == '('){
                valstr.push_back(ch);
                dfs(s, idx+1, bal+1, valstr);
                valstr.pop_back();
            }else{
                valstr.push_back(ch);
                dfs(s, idx+1, bal-1, valstr);
                valstr.pop_back();
            }
            dfs(s, idx+1, bal, valstr);
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        string valstr;
        dfs(s, 0, 0, valstr);
        vector<string> ans;
        int maxl = 0;
        if(myset.empty()) return ans;
        for(auto x : myset){
            int len = x.size();
            maxl = max(maxl, len);
        }
        for(auto x : myset){
            if(x.size() == maxl){
                ans.push_back(x);
            }
        }
        return ans;
    }
};