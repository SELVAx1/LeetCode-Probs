class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mpp;
        for(auto& vec : knowledge){
            mpp[vec[0]] = vec[1];
        }
        string ans = "";
        int i = 0;
        while(i < s.size()){
            if(s[i] == '('){
                int lt = i+1;
                while(i < s.size() && s[i] != ')') i++;
                string temp = s.substr(lt, i-lt);
                if(mpp.count(temp)){
                    ans += mpp[temp];
                }else{
                    ans += '?';
                }
            }else{
                ans += s[i];
            }
            i++;
        }
        return ans;
    }
};