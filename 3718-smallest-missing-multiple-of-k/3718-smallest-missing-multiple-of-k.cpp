class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<bool> arr(101, 0);
        for(int x : nums){
            if(x % k == 0){
                arr[x/k] = 1;
            }
        }
        for(int i = 1;  ; i++){
            if(arr[i] == 0){
                return i * k;
            }
        }
        return 0;
    }
};