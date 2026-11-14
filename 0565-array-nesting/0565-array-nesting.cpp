class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int maxlen = 0;
        int N = nums.size();
        for(int i = 0; i < N; i++){
            int curr = i, cnt = 0;
            while(nums[curr] != -1){
                int next = nums[curr];
                nums[curr] = -1;
                curr = next;
                cnt++;
            }
            maxlen = max(maxlen, cnt);
        }
        return maxlen;
    }
};