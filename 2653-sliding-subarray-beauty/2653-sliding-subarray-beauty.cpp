class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int N = nums.size();
        vector<int> neg(51, 0);
        for(int i = 0; i < k; i++){
            if(nums[i] < 0){
                neg[-nums[i]]++;
            }
        }
        vector<int> ans;
        for(int i = k; i <= N; i++){
            int el = 0, cnt = 0;
            for(int j = 50; j >= 1; j--){
                cnt += neg[j];
                if(cnt >= x){
                    ans.push_back(-j);
                    break;
                }
            }
            if(cnt < x) ans.push_back(0);
            if(i == N) break;
            if(nums[i] < 1){
                neg[-nums[i]]++;
            }
            if(nums[i-k] < 0){
                neg[-nums[i-k]]--;
            }
        }
        return ans;
    }
};