class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int i = 0, j = people.size()-1;
        int cnt = 0;
        sort(people.begin(), people.end());
        set<int> indst;
        while(i < j){
            if(people[i] + people[j] <= limit){
                cnt++;
                indst.insert(i);
                indst.insert(j);
                i++, j--;
            }else{
                j--;
            }
        }
        while(j < people.size()){
            if(!indst.count(j))
                cnt++;
            j++;
        }
        return cnt;
    }
};