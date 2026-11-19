class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int R = mat.size(), C = mat[0].size();
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<>> pq;
        for(int i = 0; i < R; i++){
            int cnt = 0;
            for(int j = 0; j < C; j++){
                if(mat[i][j] == 1) cnt++;
            }
            pq.push({cnt, i});
        }
        
        vector<int> ans;
        while(ans.size() != k && !pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};