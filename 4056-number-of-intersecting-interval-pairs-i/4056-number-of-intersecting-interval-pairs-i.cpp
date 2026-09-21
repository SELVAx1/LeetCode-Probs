class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        });
        int cnt = 0;
        for(int i = 0; i < intervals.size(); i++){
            for(int j = i+1; j < intervals.size(); j++){
                if(intervals[j][0] <= intervals[i][1])
                    cnt++;
            }
        }
        return cnt;
    }
};