// using ll = long long;
class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string> ans;
        for(int i = 0 ; i < nums.size(); i++){
            int val = nums[i];
            string s;
            int zpow = 1 << 25;
            while(val >= zpow){
                val -= zpow;
                s += 'z';
            }
            for(int p = 24; p >= 0; p--){
                int power = 1 << p;
                if(val >= power){
                    val -= power;
                    s += char('a' + p);
                }
            }
            ans.push_back(s);
        }
        return ans;
    }
};