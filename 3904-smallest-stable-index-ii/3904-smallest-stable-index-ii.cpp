class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int N=nums.size();
        int ans=INT_MAX;
        vector<int>pref(N),suff(N);
        pref[0]=nums[0];
        for(int i=1;i<N;i++){
            pref[i]=max(pref[i-1],nums[i]);
        }
        suff[N-1]=nums[N-1];
        for(int i=N-2;i>=0;i--){
            suff[i]=min(suff[i+1],nums[i]);
        }
        for(int i=0;i<N;i++){
            if(pref[i]-suff[i]<=k){
                return i;
            }
        }
        return -1;
    }
};