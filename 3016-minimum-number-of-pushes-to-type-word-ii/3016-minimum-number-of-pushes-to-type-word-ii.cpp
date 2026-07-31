class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26,0);
        for(int i = 0; i < word.size(); i++){
            freq[word[i]-'a']++;
        }
        sort(freq.begin(), freq.end(), greater<int>());
        int ans = 0, sum = 1;
        for(int i = 0; i < 26; i++){
            ans += (sum*freq[i]);
            if((i+1)%8 == 0)
                sum += 1;
        }
        return ans;
    }
};