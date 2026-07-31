class Solution {
public:
    int diff[5] = {0, -1, 0, 1, 0};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int R = isWater.size();
        int C = isWater[0].size();
        vector<vector<int>> ans(R, vector<int> (C,0));
        vector<vector<int>> vis(R, vector<int> (C,0));
        queue<pair<int, int>>q;
        for(int row = 0; row < R; row++){
            for(int col = 0; col < C; col++){
                if(isWater[row][col] == 1){
                    q.push({row, col});
                    ans[row][col] = 0;
                    vis[row][col] = 1;
                }
            }
        }
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int adjr = row + diff[i];
                int adjc = col + diff[i+1];
                if(adjr >= 0 && adjr < R && adjc >=0 && adjc < C && vis[adjr][adjc] == 0){
                    ans[adjr][adjc] = ans[row][col] + 1;
                    vis[adjr][adjc] = 1;
                    q.push({adjr,adjc});
                }
            }
        }
        return ans;
    }
};