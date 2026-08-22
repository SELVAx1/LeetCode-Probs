class Trie{
public:
    string word;
    Trie* chars[26];
    Trie(){
        word = "";
        for(int i = 0; i < 26; i++){
            chars[i] = NULL;
        }
    }
};
class Solution {
public:
    int diff[5] = {0,1,0,-1,0};
    void dfs(vector<vector<char>>& board, Trie* t, vector<string>& ans, vector<vector<bool>>& vis, int R, int C, int row, int col){
        int chidx = board[row][col] - 'a';
        if(t->chars[chidx] == NULL){
            return ;
        }
        Trie* curr = t->chars[chidx];
        if(!curr->word.empty()){
            ans.push_back(curr->word);
            curr->word = "";
        }
        vis[row][col] = true;
        for(int i = 0; i < 4; i++){
            int adjr = row + diff[i];
            int adjc = col + diff[i+1];
            if(adjr >= 0 && adjr < R && adjc >= 0 && adjc < C && !vis[adjr][adjc]){
                dfs(board, curr, ans, vis, R, C, adjr, adjc);
            }
        }
        vis[row][col] = false;
    }
    void buildTrie(Trie* p, string& word, int idx){
        int chidx = word[idx] - 'a';
        if(p->chars[chidx] == NULL){
            p->chars[chidx] = new Trie();
        }
        Trie* curr = p->chars[chidx];
        if(idx == word.size()-1){
            curr->word = word;
            return ;
        }
        buildTrie(curr, word, idx+1);
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* root = new Trie();
        for(string word : words){
            buildTrie(root, word, 0);
        }
        vector<string> ans;
        int R = board.size(), C = board[0].size();
        vector<vector<bool>> vis(R, vector<bool>(C,false));
        for(int row = 0; row < R; row++){
            for(int col = 0; col < C; col++){
                dfs(board, root, ans, vis, R, C, row, col);
            }
        }
        return ans;
    }
};