using ll = long long;
class Solution {
public:
    int shortestPath(int N, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(N);
        for(auto x : edges){
            adj[x[0]].push_back({x[1], x[2]});
        }

        vector<vector<ll>> dist(N, vector<ll> (k+1, INT_MAX));
        using state = tuple<ll, int, int>;         //cost, node, repeated char
        priority_queue<state, vector<state>, greater<>> pq;
        pq.push({0, 0, 1});
        dist[0][1] = 0;
        
        while(!pq.empty()){
            auto [cost, node, run] = pq.top();
            pq.pop();
            if(node == N-1){
                return cost;
            }
            if(cost > dist[node][run]) continue;
            for(auto &x : adj[node]){
                ll nwcost = cost + x.second;
                int nwnode = x.first;
                int nwrun = (labels[nwnode] == labels[node]) ? run+1 : 1;
                if(nwrun > k || nwcost >= dist[nwnode][nwrun]){
                    continue;
                }
                dist[nwnode][nwrun] = nwcost;
                pq.push({nwcost, nwnode, nwrun});
            }
        }
        return -1;
    }
};