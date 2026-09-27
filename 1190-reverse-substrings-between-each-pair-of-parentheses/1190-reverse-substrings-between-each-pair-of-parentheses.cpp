class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        int N = s.size();
        vector<int> link(N);
        for(int i = 0; i < N; i++){
            if(s[i] == '('){
                st.push(i);
            }else if(s[i] == ')'){
                link[i] = st.top();
                link[link[i]] = i;
                st.pop();
            }
        }
        string ans = "";
        int dir = 1;
        for(int i = 0; i < N; i += dir){
            if(isalpha(s[i])){
                ans += s[i];
            }else{                  
                i = link[i];
                dir = -dir;
            }
        }
        return ans;
    }
};