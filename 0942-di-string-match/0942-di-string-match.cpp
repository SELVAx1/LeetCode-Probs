class Solution {
public:
    vector<int> diStringMatch(string s) {
        int N = s.size();
        vector<int>ans;
        int st = 0, i = 0;
        while(i < s.size()){
            if(s[i] == 'I'){
                ans.push_back(st++);
            }else{
                ans.push_back(N--);
            }
            i++;
        }
        ans.push_back(st);
        return ans;
    }
};