class Solution {
private:
    int find(vector<int>& leader,int node){
        if(leader[node]!=node){
            leader[node]=find(leader,leader[node]);
        }
        return leader[node];
    }
    void join(vector<int>& leader,int lt,int rt){
        leader[find(leader,rt)]=find(leader,lt);
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int N=isConnected.size();
        vector<int>leader(N);
        for(int i=0;i<N;i++){
            leader[i]=i;
        }
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                if(isConnected[i][j]==1){
                    join(leader,i,j);
                }
            }
        }
        int provinces=0;
        for(int i=0;i<N;i++){
            if(find(leader,i)==i){
                provinces++;
            }
        }
        return provinces;
    }
};