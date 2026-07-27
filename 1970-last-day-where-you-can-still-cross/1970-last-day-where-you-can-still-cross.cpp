class Solution {
private:
    void join(vector<int>& leader,int lt,int rt){
        leader[find(leader,rt)]=find(leader,lt);
    }
    int find(vector<int>& leader,int node){
        if(leader[node]!=node){
            leader[node]=find(leader,leader[node]);
        }
        return leader[node];
    }
public:
    int xdiff[8]={0,0,1,-1,-1,1,-1,1};
    int ydiff[8]={1,-1,0,0,-1,-1,1,1};
    int latestDayToCross(int R, int C, vector<vector<int>>& cells) {
        vector<int>leader(R*C+2,0);
        vector<bool>water(R*C+2,0);
        for(int i=0;i<R*C+2;i++){
            leader[i]=i;
        }
        int days=0;
        for(auto vec:cells){
            int row=vec[0];
            int col=vec[1];
            row--,col--;                    //0 based index
            water[row*C+col+1]=true;
            for(int i=0;i<8;i++){
                int adjr=row+xdiff[i];
                int adjc=col+ydiff[i];
                if(adjr>=0 && adjr<R && adjc>=0 && adjc<C && water[adjr*C+adjc+1]==1){
                    join(leader,row*C+col+1,adjr*C+adjc+1);
                }
            }
            if(col==0){
                join(leader,0,row*C+col+1);
            }else if(col==C-1){
                join(leader,row*C+col+1,R*C+1);
            }
            if(find(leader,0)==find(leader,R*C+1)) break;
            days++;
        }
        return days;
    }
};