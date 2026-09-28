class Solution {
public:
    string lastNonEmptyString(string s) {
        string res = "";
        int cnt = 0;
        unordered_map<char, int> mpp;
        for(char ch : s){
            mpp[ch]++;
            cnt = max(cnt, mpp[ch]);
        }
        set<char> set;
        for(int i = s.size()-1; i >= 0; i--){
            if(!set.contains(s[i]) && mpp[s[i]] == cnt){
                res += s[i];
                set.insert(s[i]);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};