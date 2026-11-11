using ll = long long;
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        ll c1sum = 0, c2sum = 0, c3sum = 0;                // c1 + c2 only, cb only, cb + c1 + c2
        
        //case1:
        c1sum = (1LL * need1 * cost1);
        c1sum += (1LL * need2 * cost2);
        
        //case2:
        c2sum = 1LL * max(need1, need2) * costBoth;
        
        //case3:
        int needboth = min(need1, need2);
        c3sum = 1LL * needboth * costBoth;
        int diff = abs(need1 - need2);
        if(need1 > need2){
            c3sum += (1LL * diff * cost1);
        }else{
            c3sum += (1LL * diff * cost2);
        }
        return min({c1sum, c2sum, c3sum});
    }
};