class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int N = nums.size();
        int lt = 0, rt = N-1;
        long long ltsum = 0, rtsum = 0;
        while(lt < N-1 && nums[lt] < nums[lt+1]){
            ltsum += nums[lt];
            lt++;
        }
        while(rt > 0 && nums[rt-1] > nums[rt]){
            rtsum += nums[rt];
            rt--;
        }
        if(lt == rt){
            long long op1 = llabs((ltsum + nums[lt]) - rtsum);
            long long op2 = llabs((rtsum + nums[rt]) - ltsum);
            return min(op1, op2);
        }else if(rt - lt == 1){
            return llabs(ltsum - rtsum);
        }
        return -1;
    }
};