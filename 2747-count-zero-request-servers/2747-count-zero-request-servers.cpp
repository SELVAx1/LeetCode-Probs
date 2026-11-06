class Solution {
public:
    vector<int> countServers(int N, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int qlen = queries.size();
        using pii = pair<int, int>;
        vector<pii> q(qlen);
        vector<int> ans(qlen);
        for(int i = 0; i < qlen; i++){
            q[i] = {queries[i], i};
        }

        sort(q.begin(), q.end());
        sort(logs.begin(), logs.end(), [](const vector<int> &a, const vector<int> &b){
            return a[1] < b[1];
        });
        
        int active = 0, lt = 0, rt = 0;
        vector<int> serv(N+1, 0);
        for(auto &[time, idx] : q){
            while(rt < logs.size() && logs[rt][1] <= time){
                if(serv[logs[rt][0]] == 0){
                    active++;
                }
                serv[logs[rt][0]]++;
                rt++;
            }
            while(lt < rt && logs[lt][1] < time-x){
                serv[logs[lt][0]]--;
                if(serv[logs[lt][0]] == 0){
                    active--;
                }
                lt++;
            }
            ans[idx] = N - active;
        }
        return ans;
    }
};