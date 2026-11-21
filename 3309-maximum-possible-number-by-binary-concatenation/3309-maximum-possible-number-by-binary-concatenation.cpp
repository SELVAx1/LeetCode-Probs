class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {
        vector<string> a;
        for(int x : nums){
            a.push_back(format("{:b}", x));
        }
        sort(a.begin(), a.end(), [](const auto& s1, const auto& s2){
            return s1 + s2 > s2 + s1;
        });
        string bin = "";
        for(auto s : a){
            bin += s;
        }
        return stoi(bin, nullptr, 2);
    }
};