using ll = long long;
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        //base
        if(tx < sx || ty < sy) return 0;
        if(tx == sx && ty == sy) return 1;
        if(tx == sx) return (ty - sy) % tx == 0;
        if(ty == sy) return (tx - sx) % ty == 0;
        if(tx > ty){
            return reachingPoints(sx, sy, tx%ty, ty);
        }else if(ty > tx){
            return reachingPoints(sx, sy, tx, ty%tx);
        }
        return 0;
    }
};