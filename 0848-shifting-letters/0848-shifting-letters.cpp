class Solution {
public:
    using ll = long long;
    string shiftingLetters(string s, vector<int>& shifts) {
        int N = shifts.size();
        vector<ll> suff(N);
        ll tot = 0;
        for(int i = N-1; i >= 0; i--){
            tot += 1LL * shifts[i] ;
            suff[i] = tot;
        }
        for(int i = 0; i < N; i++){
            ll ch = ((1LL * s[i] + suff[i] - 97) % 26);
            // cout << ch << " ";
            s[i] = char(ch + 'a');
        }
        return s;
    }
};