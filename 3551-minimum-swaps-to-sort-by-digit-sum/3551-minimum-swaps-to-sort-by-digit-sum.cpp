class Solution {
public:
    int minSwaps(vector<int>& nums) {
        auto digitSum = [](int temp){
            int ds = 0;
            while(temp){
                ds += temp % 10;
                temp /= 10;
            }
            return ds;
        };
        
        int N = nums.size();
        vector<int> idx(N);
        iota(idx.begin(), idx.end(), 0);
            
        sort(idx.begin(), idx.end(), [&](int a, int b){
            int ads = digitSum(nums[a]), bds = digitSum(nums[b]);
            if(ads == bds){
                return nums[a] < nums[b];
            }
            return ads < bds;
        });
        
        int ans = 0;
        vector<int> vis(N, 0);
        for(int i = 0; i < N; i++){
            if(vis[i] || idx[i] == i) continue;
            int cycle = 0;
            int j = i;
            while(!vis[j]){
                vis[j] = 1;
                j = idx[j];
                cycle++;
            }
            ans += (cycle - 1);
        }
        return ans;
    }
};