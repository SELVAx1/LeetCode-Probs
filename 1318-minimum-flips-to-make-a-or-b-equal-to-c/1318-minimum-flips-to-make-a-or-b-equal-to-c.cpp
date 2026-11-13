class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        string as = bitset<32> (a).to_string();
        string bs = bitset<32> (b).to_string();
        string cs = bitset<32> (c).to_string();
        for(int i = 0; i < 32; i++){
            if(cs[i] == '1'){
                if(as[i] == '1' || bs[i] == '1') continue;
                else ans++;
            }else{
                if(as[i] == '0' && bs[i] == '0') continue;
                else if(as[i] == '1' && bs[i] == '1') ans += 2;
                else ans++; 
            }
        }
        return ans;
    }
};