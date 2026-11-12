class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int res = 0, i = 0, cnt = 1;
        while(i < nums.size()){
            if(i > 0 && nums[i] > nums[i-1]){
                cnt++;
            }else{
                res = max(cnt, res);
                cnt = 1;
            }
            i++;
        }
        res = max(res, cnt);
        i = 0, cnt = 1;
        while(i < nums.size()){
            if(i > 0 && nums[i] < nums[i-1]){
                cnt++;
            }else{
                res = max(cnt, res);
                cnt = 1;
            }
            i++;
        }
        res = max(res, cnt);
        return res;
    }
};