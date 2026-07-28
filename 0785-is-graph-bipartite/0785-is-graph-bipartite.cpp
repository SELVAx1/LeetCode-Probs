class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int N=graph.size();
        vector<int>color(N,-1);
        for(int i=0;i<N;i++){
            if(color[i]!=-1) continue;

            queue<int>q;
            color[i]=0;
            q.push(i);
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(auto it:graph[node]){
                    if(color[it]==-1){
                        color[it]=!color[node];
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