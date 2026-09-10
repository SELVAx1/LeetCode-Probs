/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    pair<int, int> dfs(TreeNode* root){
        if(!root) return {0, 0};
        auto [ln, lc] = dfs(root->left);
        auto [rn, rc] = dfs(root->right);
        int sum = ln + rn + root->val;
        int cnt = lc + rc + 1;
        if(root->val == sum/cnt)
            ans++;
        return {sum, cnt}; 
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};