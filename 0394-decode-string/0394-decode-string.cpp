class Solution {
public:
    string decodeString(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]!=']'){
                st.push(s[i]);
            }else{
                string s="";
                while(!st.empty() && st.top()!='['){
                    s=st.top()+s;
                    st.pop();
                }
                st.pop();                   // delete'['
                string num="";
                while(!st.empty() && isdigit(st.top())){
                    num=st.top()+num;
                    st.pop();
                }
                int ktime=stoi(num);
                while(ktime--){
                    for(int i=0;i<s.size();i++){
                        st.push(s[i]);
                    }
                }
            }
        }
        string res="";
        while(!st.empty()){
            res=st.top()+res;
            st.pop();
        }
        return res;
    }
};