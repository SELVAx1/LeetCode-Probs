class Solution {
public:
    int compress(vector<char>& chars) {
        int ans=0;
        for(int i=0;i<chars.size();){
            char ch=chars[i];
            int cnt=0;
            while(i<chars.size()){
                if(chars[i]==ch){
                    cnt++;
                    i++;
                }else break;
            }
            chars[ans++]=ch;
            if(cnt>1){
                string cntstr=to_string(cnt);
                int p=0;
                while(p<cntstr.size()){
                    chars[ans++]=cntstr[p];
                    p++;
                }
            }
        }
        return ans;
    }
};