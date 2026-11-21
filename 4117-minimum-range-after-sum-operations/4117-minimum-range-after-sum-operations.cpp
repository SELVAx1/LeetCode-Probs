class Solution {
public:
    int minRange(int a, int b, int c) {
        while(a+b < c || b+c < a || a+c < b){
            if(a+b < c){
                c = a+b;
            }else if(b+c < a){
                a = b+c;
            }else{
                b = a+c;
            }
        }
        return max({a, b, c}) - min({a, b, c});
    }
};