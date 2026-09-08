class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ss = s.size(), ps = p.size();
        if(ss < ps) return {};
        vector<int> ans;
        vector<int> freq1(26, 0), freq2(26, 0);
        for(int i = 0; i < ps; i++){
            freq1[s[i]-'a']++;
            freq2[p[i]-'a']++;
        }
        if(freq1 == freq2)
            ans.push_back(0);
        for(int i = ps; i < ss; i++){
            freq1[s[i]-'a']++;
            freq1[s[i-ps]-'a']--;
            if(freq1 == freq2)
                ans.push_back(i-ps+1);
        }
        return ans;
    }
};