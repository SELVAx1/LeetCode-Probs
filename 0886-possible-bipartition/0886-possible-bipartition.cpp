class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<int>color(N+1,-1);
        vector<vector<int>>adjgraph(N+1);
        for(auto vec:dislikes){
            int x=vec[0];
            int y=vec[1];
            adjgraph[x].push_back(y);
            adjgraph[y].push_back(x);
        }
        for(int i=1;i<=N;i++){
            if(color[i]!=-1) continue;

            queue<int>q;
            color[i]=0;
            q.push(i);
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(auto it:adjgraph[node]){
                    if(color[it]==-1){
                        color[it]=1-color[node];
                        q.push(it);
                    }else if(color[it]==color[node]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};