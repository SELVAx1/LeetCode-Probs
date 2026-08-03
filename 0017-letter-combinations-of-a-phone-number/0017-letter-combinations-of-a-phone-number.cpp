class Solution {
private:
    void generate(string& digits, unordered_map<char, string>& mpp, vector<string>& ans, int N, string& s, int ind){
        if(s.size() == N){
            ans.push_back(s);
            return ;
        }
        string str = mpp[digits[ind]];
        for(int i = 0; i < str.size(); i++){
            s.push_back(str[i]);
            generate(digits, mpp, ans, N, s, ind+1);
            s.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mpp = {{'2',"abc"}, {'3',"def"}, {'4',"ghi"}, {'5',"jkl"}, {'6',"mno"}, {'7',"pqrs"}, {'8',"tuv"}, {'9',"wxyz"}};
        int N = digits.size();
        vector<string> ans;
        string s = "";
        generate(digits, mpp, ans, N, s, 0);
        return ans;
    }
};