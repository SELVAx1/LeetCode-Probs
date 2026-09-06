class Solution {
private:
    bool isVow(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
public:
    int maxVowels(string s, int k) {
        int lt = 0, maxans = 0, cnt = 0;
        for(int i = 0; i < s.size(); i++){
            if(isVow(s[i]))
                cnt++;
            if(i > k-1){
                if(isVow(s[lt])){
                    cnt--;
                }
                lt++;
            }
            maxans = max(maxans, cnt);
        }
        return maxans;
    }
};