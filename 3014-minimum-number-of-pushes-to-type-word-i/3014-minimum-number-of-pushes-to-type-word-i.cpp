class Solution {
public:
    int minimumPushes(string word) {
        int cnt = 0, sum = 1, i = 0;
        while(i < word.size()){
            if(cnt != 0 && i % 8 == 0)
                sum += 1;
            cnt += sum;
            i++;
        }
        return cnt;
    }
};