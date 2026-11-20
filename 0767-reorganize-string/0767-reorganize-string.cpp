class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mpp;
        for(char ch : s){
            mpp[ch]++;
        }
        priority_queue<pair<int, char>> pq;
        for(auto& [ch, freq] : mpp){
            pq.emplace(freq, ch);
        }
        string ans = "";
        while(pq.size() >= 2){
            auto [f1, ch1] = pq.top(); pq.pop();
            auto [f2, ch2] = pq.top(); pq.pop();
            ans += ch1;
            ans += ch2;
            if(--f1 > 0) pq.emplace(f1, ch1);
            if(--f2 > 0) pq.emplace(f2, ch2);
        }
        if(!pq.empty()){
            if(pq.top().first > 1) return "";
            else ans += pq.top().second;
        }
        return ans;
    }
};