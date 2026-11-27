using ll = long long;
class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        multiset<int> ms;
        int N = nums.size(), lt = 0;
        ll sum = 0;
        auto add = [&](int rt){
            if(!ms.contains(nums[rt])){
                sum += nums[rt];
            }
            ms.insert(nums[rt]);
        };
        auto del = [&](int lt){
            int todel = nums[lt];
            ms.erase(ms.find(nums[lt]));
            if(!ms.contains(todel)){
                sum -= todel;
            }
        };
        int mlen = INT_MAX;
        for(int rt = 0; rt < N; rt++){
            add(rt);
            while(sum >= k){
                mlen = min(mlen, rt - lt + 1);
                del(lt);
                lt++;
            }
        }
        return mlen == INT_MAX ? -1 : mlen;
    }
};