int reverse(int x){
    long long int rev=0;
    while(x){
        int temp=x%10;
        rev=(rev*10)+(x%10);
        x/=10;
    }
    if(rev>INT_MAX || rev<INT_MIN){
        return 0;
    }
    return rev;
}