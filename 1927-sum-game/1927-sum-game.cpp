class Solution {
public:
    bool sumGame(string num) {
        vector<int>arr;
        for(int i=0;i<num.size();i++){
            if(num[i]=='?') arr.push_back(9);
            else arr.push_back(2*(num[i]-'0'));
        }
        int N=num.size()/2;
        int fhs=accumulate(arr.begin(),arr.begin()+N,0);
        int shs=accumulate(arr.begin()+N,arr.end(),0);
        return fhs-shs!=0;
    }
};