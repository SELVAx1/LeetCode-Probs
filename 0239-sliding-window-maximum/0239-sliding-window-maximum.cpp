class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int N = nums.size();
        unordered_map<int, int> mpp;
        set<int> s;
        vector<int> ans;
        auto add = [&](int i){
            if(++mpp[nums[i]] == 1) s.insert(nums[i]);
        };
        auto del = [&](int i){
            if(--mpp[nums[i]] == 0){
                mpp.erase(nums[i]);
                s.erase(nums[i]);
            }
        };
        for(int i = 0; i < k; i++){
            add(i);
        }
        ans.push_back(*s.rbegin());
        for(int i = k; i < N; i++){
            add(i);
            del(i-k);
            ans.push_back(*s.rbegin());
        }
        return ans;
    }
};