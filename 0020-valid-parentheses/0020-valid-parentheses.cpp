class Solution {
public:
    bool isValid(string s) {
        stack<char>stack;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                stack.push(s[i]);
            }else{
                if(stack.empty()) return 0;
                char top=stack.top();
                stack.pop();
                if((s[i]==')'&&top!='(') || (s[i]=='}'&& top!='{') || (s[i]==']' && top!='[') ) return 0;
            }
        }
        if(s.size()<=1 || !stack.empty()) return 0;
        return 1;
    }
};