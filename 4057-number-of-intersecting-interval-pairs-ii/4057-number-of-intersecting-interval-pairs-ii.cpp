class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        // sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
        //     return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        // });
        long long cnt = 0;
        multiset<int> set;
        sort(intervals.begin(), intervals.end());
        set.insert(intervals[0][1]);
        for(int i = 1; i < intervals.size(); i++){
            auto it = set.lower_bound(intervals[i][0]);
            set.erase(set.begin(), it);
            cnt += set.size(); 
            set.insert(intervals[i][1]);
        }
        return cnt;
    }
};