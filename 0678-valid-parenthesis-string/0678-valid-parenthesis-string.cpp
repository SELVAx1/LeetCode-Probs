class Solution {
public:
    bool checkValidString(string s) {
        stack<int> ost, sst;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                ost.push(i);
            }else if(s[i] == '*'){
                sst.push(i);
            }else{
                if(!ost.empty()){
                    ost.pop();
                }else if(!sst.empty()){
                    sst.pop();
                }else{
                    return 0;
                }
            }
        }
        while(!ost.empty() && !sst.empty()){
            if(ost.top() > sst.top()){
                return 0;
            }
            ost.pop(), sst.pop();
        }
        return ost.empty();
    }
};