class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> s1, s2;
        vector<double> ans;
        auto s2_to_s1 = [&](){
            s1.insert(*s2.begin());
            s2.erase(s2.begin());
        };
        auto s1_to_s2 = [&](){
            s2.insert(*s1.rbegin());
            s1.erase(prev(s1.end()));
        };
        auto add = [&](int i){
            s2.insert(nums[i]);
            s2_to_s1();
            if(s1.size() >= s2.size() + 2){
                s1_to_s2();
            }
        };
        auto del = [&](int i){
            if(s2.find(nums[i]) != s2.end()){
                s2.erase(s2.find(nums[i]));
            }else{
                s1.erase(s1.find(nums[i]));
            }
            if(s1.size() >= s2.size() + 2){
                s1_to_s2();
            }
            if(s2.size() > s1.size()){
                s2_to_s1();
            }
        };
        for(int i = 0; i < k; i++){
            add(i);
        }
        long double val;
        val = (k % 2 == 0) ? double((1LL * *s1.rbegin() + *s2.begin()) / 2.0) : double(*s1.rbegin());
        ans.push_back(val);
        for(int i = k; i < nums.size(); i++){
            add(i);
            del(i-k);
            val = (k % 2 == 0) ? double((1LL * *s1.rbegin() + *s2.begin()) / 2.0) : double(*s1.rbegin());
            ans.push_back(val);
        }
        return ans;
    }
};