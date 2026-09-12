class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        int rt = INT_MIN;
        int cnt = 0;
        for(auto& vec : intervals){
            if(vec[0] > rt){
                cnt++;
                rt = vec[1] - 1;
            }
        }
        return intervals.size() - cnt;
    }
};