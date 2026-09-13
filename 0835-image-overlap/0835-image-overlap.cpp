class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<vector<int>> A,B;
        int N = img1.size();
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(img1[i][j] == 1){
                    A.push_back({i, j});
                }
                if(img2[i][j] == 1){
                    B.push_back({i, j});
                }
            }
        }
        map<pair<int,int>, int> mpp;
        int ans = 0;
        for(auto a : A){
            for(auto b : B){
                int rowd = b[0] - a[0];
                int cold = b[1] - a[1];
                mpp[{rowd, cold}]++;
                ans = max(ans, mpp[{rowd, cold}]);
            }
        }
        return ans;
    }
};