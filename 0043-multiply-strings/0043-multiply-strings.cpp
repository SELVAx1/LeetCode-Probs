class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";
        int N1=num1.size(),N2=num2.size();
        vector<int>ans(N1+N2,0);
        for(int i=N1-1;i>=0;i--){
            for(int j=N2-1;j>=0;j--){
                int mul=(num1[i]-'0')*(num2[j]-'0');
                int sum=ans[i+j+1]+mul;
                ans[i+j+1]=sum%10;
                ans[i+j]+=sum/10;
            }
        }
        int i=0;
        while(i<ans.size() && ans[i]==0) i++;
        string s="";
        while(i<ans.size()){
            s+=ans[i]+'0';
            i++;
        }
        return s;
    }
};