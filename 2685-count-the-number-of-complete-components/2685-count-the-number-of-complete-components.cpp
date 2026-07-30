class Solution {
public:
    int find(vector<int>& parent, int node){
        if(parent[node] == node)
            return node;
        return parent[node] = find(parent, parent[node]);
    }
    void Union(vector<int>& parent, int lt, int rt){
        parent[find(parent, rt)] = find(parent, lt);
    }
    int countCompleteComponents(int N, vector<vector<int>>& edges) {
        vector<int> parent(N);
        iota(parent.begin(), parent.end(), 0);
        for(int i = 0; i < edges.size(); i++){
            int x =  edges[i][0];
            int y =  edges[i][1];
            Union(parent, x, y);
        }
        unordered_map<int, int> nodes,edgecnt;
        for(int i = 0; i < N; i++){
            nodes[find(parent, parent[i])]++;
        }
        for(auto &e : edges){
            edgecnt[find(parent, e[0])]++;
        }
        int ans = 0;
        for(auto &it : nodes){
            int leader = it.first;
            int k = it.second;
            if(edgecnt[leader] == (k*(k-1))/2)
                ans++;
        }
        return ans;
    }
};