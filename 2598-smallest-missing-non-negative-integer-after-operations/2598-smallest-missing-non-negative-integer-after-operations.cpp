class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> mpp;
        for(auto x : nums){
            int rem = ((x % value )+ value) % value;         // handle neg
            mpp[rem]++;
        }
        int mex = 0;
        while(1){
            int rem = mex % value;
            if(!mpp.contains(rem)) return mex;
            if(--mpp[rem] == 0){
                mpp.erase(rem);
            }
            mex++;
        }
        return 0;
    }
};