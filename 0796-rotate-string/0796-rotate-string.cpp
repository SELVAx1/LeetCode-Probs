class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return 0;
        string newstr = s + s;
        if(newstr.find(goal) != -1) return 1;
        return 0;
    }
};