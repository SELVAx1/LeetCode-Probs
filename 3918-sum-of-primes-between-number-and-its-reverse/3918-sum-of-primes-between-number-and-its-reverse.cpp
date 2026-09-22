class Solution {
public:
    int sumOfPrimesInRange(int n) {
        vector<bool> prime(1001, 1);
        prime[0] = prime[1] = 0;
        for(int i = 2; i*i <= 1000; i++){
            if(prime[i] == 1){
                for(int j = i*i; j <= 1000; j+=i){
                    prime[j] = 0;
                }
            }
        }
        int temp = n;
        int rev = 0;
        while(temp){
            rev = rev*10 + (temp%10);
            temp/=10;
        }
        if(n > rev){
            swap(n, rev);
        }
        int sum = 0;
        for(int i = n; i <= rev; i++){
            if(prime[i]){
                sum += i;
            }
        }
        return sum;
    }
};