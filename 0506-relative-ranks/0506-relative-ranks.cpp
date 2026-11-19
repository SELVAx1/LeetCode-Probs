class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<string, string> mpp = {{"1", "Gold Medal"}, {"2", "Silver Medal"}, {"3", "Bronze Medal"}};
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < score.size(); i++){
            pq.push({score[i], i});
        }
        int N = score.size();
        vector<string> ans(N);
        int cnt = 1;
        while(!pq.empty()){
            string s = to_string(cnt);
            if(mpp.contains(s)) s = mpp[s];
            ans[pq.top().second] = s;
            cnt++;
            pq.pop();
        }
        return ans;
    }
};