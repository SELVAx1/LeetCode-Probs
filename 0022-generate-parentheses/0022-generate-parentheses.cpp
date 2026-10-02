class Solution {
private:
    void gen(vector<string>& ans,int n, int op, int cl, string str){
        if(str.size()==2*n){
            ans.push_back(str);
            return ;
        }
        if(op<n){
            gen(ans,n,op+1,cl,str+'(');
        }
        if(cl<op){
            gen(ans,n,op,cl+1,str+')');
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        gen(ans,n,0,0,"");
        return ans;
    }
};