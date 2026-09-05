class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        int N = nums.size();
        vector<int> suff(N, 0);
        suff[N-1] = nums[N-1];
        for(int i = N-2; i >= 0; i--){
            suff[i] = nums[i] + suff[i+1];
        }
        for(int i = 0; i < N ; i++){
            sum += (i != 0) ? nums[i-1] : 0;
            if(i != N-1){
                if(sum == suff[i+1])
                    return i;
            }else{
                if(sum == 0)
                    return N-1;
            }
        }
        return -1;
    }
};