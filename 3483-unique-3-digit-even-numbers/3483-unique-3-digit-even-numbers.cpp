class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<int>uniq;
        int size=digits.size();
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                for(int k=0;k<size;k++){
                    if(i!=j && j!=k && k!=i){
                        if(digits[i]!=0){
                            if(digits[k]%2==0){
                                int ans=digits[i]*100+digits[j]*10+digits[k];
                                uniq.insert(ans);
                            }
                        }
                    }
                }
            }
        }
        return uniq.size();
    }
};