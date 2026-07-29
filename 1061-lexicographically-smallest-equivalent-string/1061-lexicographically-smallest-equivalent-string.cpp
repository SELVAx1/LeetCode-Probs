class Solution {
public:
    void unite(vector<int>& parent, int lt, int rt){
        int x = find(parent, lt);
        int y = find(parent, rt);
        if(x == y) return ;
        else if(x < y) parent[y] = x;
        else parent[x] = y;
    }
    int find(vector<int>& parent, int node){
        if(parent[node] != node)
            parent[node] = find(parent, parent[node]);
        return parent[node];
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int N = s1.size();
        vector<int> parent(26);
        iota(parent.begin(), parent.end(), 0);
        for(int i = 0; i < N; i++){
            unite(parent, s1[i] - 'a', s2[i] - 'a');
        }
        int size = baseStr.size();
        string ans;
        for(int i = 0; i < size; i++){
            ans.push_back(find(parent, baseStr[i] - 'a') + 'a'); 
        }
        return ans;
    }
};