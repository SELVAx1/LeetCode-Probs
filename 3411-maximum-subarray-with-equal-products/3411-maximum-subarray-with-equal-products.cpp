class Solution {
public:
    int maxLength(vector<int>& nums) {
        int N = nums.size();
        int ans = 0;
        for(int i = 0; i < N; i++){
            int pro = 1;
            for(int j = i; j < N; j++){
                pro *= nums[j];
                int fgcd = accumulate(nums.begin()+i, nums.begin()+j+1, 0, [](int a, int b){
                    return gcd(a, b);
                });
                int flcm = accumulate(nums.begin()+i, nums.begin()+j+1, 1, [](int a, int b){
                    return lcm(a, b);
                });
                if(pro == (flcm * fgcd)){
                    ans = max(ans, j - i + 1);
                }
                if(pro > 25200) break;
            }
        }
        return ans;
    }
};