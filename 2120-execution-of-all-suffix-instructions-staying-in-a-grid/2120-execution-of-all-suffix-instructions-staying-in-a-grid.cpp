class Solution {
public:
    vector<int> executeInstructions(int N, vector<int>& startPos, string s) {
        int M = s.size();
        vector<int> ans(M);
        for(int i = 0; i < M; i++){
            int cnt = 0, row = startPos[0], col = startPos[1];
            for(int j = i; j < M; j++){
                if(s[j] == 'R') col++;
                else if(s[j] == 'L') col--;
                else if(s[j] == 'U') row--;
                else row++;
                if(row < 0 || row == N || col < 0 || col == N) break;
                cnt++; 
            }
            ans[i] = cnt;
        }
        return ans;
    }
};