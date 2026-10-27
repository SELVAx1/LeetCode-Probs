class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string str(n, '#');
        vector<string> ans(m, str);
        for(int i = 0; i < m; i++){
            ans[i][0] = '.';
        }
        for(int i = 0; i < n; i++){
            ans[m-1][i] = '.';
        }
        return ans;
    }
};