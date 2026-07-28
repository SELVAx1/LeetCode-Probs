class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int>& temp, int currnode, int target) {
        temp.push_back(currnode);
        if (currnode == target) {
            ans.push_back(temp);
        }
        for (int node : graph[currnode]) {
            dfs(graph, ans, temp, node, target);
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int target = graph.size() - 1;
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(graph, ans, temp, 0, target);
        return ans;
    }
};