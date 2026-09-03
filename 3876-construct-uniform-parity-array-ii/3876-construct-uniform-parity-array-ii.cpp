class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minel = *min_element(nums1.begin(), nums1.end());
        if(minel&1)
            return true;
        int oddcnt = 0, evncnt = 0;
        for(int x : nums1){
            if(x&1)
                oddcnt++;
            else
                evncnt++;
        }
        int N = nums1.size();
        if(evncnt == N)              // if min is odd or all even
            return 1;
        return 0;
    }
};