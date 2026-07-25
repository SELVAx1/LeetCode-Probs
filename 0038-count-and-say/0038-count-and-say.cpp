class Solution {
private:
    string RLE(string& s){
        string res="";
        int count=1;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                count++;
            }else{
                res+=to_string(count)+s[i-1];
                count=1;
            }
        }
        res+=to_string(count)+s.back();
        return res;
    }
public:
    string countAndSay(int n) {
        string ans="1";
        for(int i=1;i<n;i++){
            cout<<ans<<endl;
            ans=RLE(ans);
        }
        return ans;
    }
};