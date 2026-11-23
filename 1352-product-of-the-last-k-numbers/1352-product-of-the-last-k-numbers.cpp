class ProductOfNumbers {
public:
    vector<int> pref{1};

    ProductOfNumbers() {    }
    
    void add(int num) {
        if(num == 0){
            pref.clear();
            pref.push_back(1);
        }else{
            pref.push_back(pref.back() * num);
        }
    }
    
    int getProduct(int k) {
        int N = pref.size();
        if(k >= N) return 0;
        return pref[N-1]/pref[N-1-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */