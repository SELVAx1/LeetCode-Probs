using ll = long long;
class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        auto cmp = [](const auto& a, const auto& b){
            if(a.first == b.first) return a.second > b.second;
            return a.first > b.first;
        };
        using pii = pair<int, int>;
        set<pii, decltype(cmp)> top, rest;     
        unordered_map<int, int> mpp;
        vector<ll> ans;
        int N = nums.size();
        ll sum = 0;
        
        auto check = [&](){
            if(top.size() < x && !rest.empty()){
                sum += (1LL * rest.begin()->first * rest.begin()->second);
                top.insert(*rest.begin());
                rest.erase(rest.begin());
            }else{
                if(!top.empty() && !rest.empty() && cmp(*rest.begin(), *top.rbegin())){
                    sum -= (1LL * top.rbegin()->first * top.rbegin()->second);
                    sum += (1LL * rest.begin()->first * rest.begin()->second);
                    top.insert(*rest.begin());
                    rest.insert(*top.rbegin());
                    top.erase(prev(top.end()));
                    rest.erase(rest.begin());
                }
            }
        };
        auto add = [&](int i){
            int a = nums[i];
            if(mpp.contains(a)){
                if(top.contains({mpp[a], a})){
                    top.erase({mpp[a], a});
                    mpp[a]++;
                    top.insert({mpp[a], a});
                    sum += a;
                }else{
                    rest.erase({mpp[a], a});
                    mpp[a]++;
                    rest.insert({mpp[a], a});
                }
            }else{
                mpp[a]++;
                rest.insert({1, a});
            }
            check();
        };
        auto del = [&](int i){
            int a = nums[i];
            if(top.contains({mpp[a], a})){
                sum -= (1LL * mpp[a] * a);
                top.erase({mpp[a], a});
                mpp[a]--;
                if(mpp[a] == 0){
                    mpp.erase(a);
                    check();
                    return ;
                }else{
                    top.insert({mpp[a], a});
                    sum += (1LL * mpp[a] * a);
                    check();
                }
            }else{
                rest.erase({mpp[a], a});
                mpp[a]--;
                if(mpp[a] == 0){
                    mpp.erase(a);
                    return ;
                }else{
                    rest.insert({mpp[a], a});
                }
            }
        };
        for(int i = 0; i < k; i++){
            add(i);
        }
        ans.push_back(sum);
        for(int i = k; i < N; i++){
            add(i);
            del(i-k);
            ans.push_back(sum);
        }
        return ans;
    }
};