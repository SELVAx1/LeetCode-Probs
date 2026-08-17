class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int N = heights.size();
        vector<int> lt(N), rt(N);
        stack<int> st;
        for(int i = 0; i < N; i++){
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            lt[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        for(int i = N-1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            rt[i] = (st.empty()) ? N : st.top();
            st.push(i);
        }
        int ans = 0;
        for(int i = 0; i < N; i++){
            int width = rt[i] - lt[i] - 1;
            ans = max(ans, heights[i]*width);
        }
        return ans;
    }
};