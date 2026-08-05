class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<bool> infec(n, 1);
        vector<vector<int>> adj(n);
        for(auto &inv : invocations){
            adj[inv[0]].push_back(inv[1]);
        }
        queue<int> q;
        q.push(k);
        infec[k] = 0;
        while(!q.empty()){
            int el = q.front();
            q.pop();
            for(auto x : adj[el]){
                if(infec[x] == 1){
                    infec[x] = 0;
                    q.push(x);
                }
            }
        }
        int flg = 0;
        for(auto &inv : invocations){
            if(infec[inv[0]] == 1 && infec[inv[1]] == 0) {
                flg = 1;
                break;
            }
        }
        vector<int> ans;
        if(flg){
            for(int i = 0; i < n; i++){
                if(!infec[i]) infec[i] = 1;
            }
        }
        for(int i = 0; i < n; i++){
            if(infec[i] == 1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};