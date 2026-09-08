class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int lt = 0, rt = 0, ans = 0;
        int N = nums.size();
        int cnt = 0;
        while(rt < N){
            if(nums[rt] == 0){
                cnt++;
            }
            while(cnt > k){
                if(nums[lt] == 0){
                    cnt--;
                }
                lt++;
            }
            ans = max(ans, rt-lt+1);
            rt++;
        }
        return ans;
    }
};