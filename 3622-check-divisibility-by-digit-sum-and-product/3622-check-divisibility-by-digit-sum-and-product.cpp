class Solution {
public:
    bool checkDivisibility(int n) {
        int pro = 1, sum = 0;
        int temp = n;
        while(temp){
            int dig = temp%10;
            pro *= dig;
            sum += dig;
            temp/=10;
        }
        return !(n % (pro+sum));
    }
};