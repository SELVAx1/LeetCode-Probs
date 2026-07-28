class Solution {
private:
    bool check(vector<vector<int>>& graph,vector<int>& color,int start){
        queue<int>q;
        q.push(start);
        color[start]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:graph[node]){
                if(color[it]==-1){
                    color[it]= !color[node];
                    q.push(it);
                }else if(color[it]==color[node]){                          //if same color {0,1} , nocolor{-1}
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int N=graph.size();
        vector<int>color(N,-1);
        for(int i=0;i<N;i++){
            if(color[i]==-1){
                if(check(graph,color,i)==false){
                    return false;
                }
            }
        }
        return true;
    }
};