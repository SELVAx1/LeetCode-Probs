class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int N = seq.size();
        vector<int> ans(N);
        int ao = 0, bo = 0;
        for(int i = 0; i < N; i++){
            if(seq[i] == '('){
                if(ao < bo){
                    ao++;
                    ans[i] = 0;
                }else{
                    bo++;
                    ans[i] = 1;
                }
            }else{
                if(ao){
                    ao--;
                    ans[i] = 0;
                }else{
                    bo--;
                    ans[i] = 1;
                }
            }
        }
        return ans;
    }
};