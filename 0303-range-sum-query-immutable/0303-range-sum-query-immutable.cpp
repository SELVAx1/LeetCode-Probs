class NumArray {
public:
    vector<int> pref;
    NumArray(vector<int>& nums) {
        pref.push_back(nums[0]);
        int tot = nums[0];
        for(int i = 1; i < nums.size(); i++){
            tot += nums[i];
            pref.push_back(tot);
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0){
            return pref[right];
        }
        return pref[right] - pref[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */