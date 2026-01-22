class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> prefix(n);
        stack<int> st1;
        prefix[0] = -1;
        st1.push(0);
        for(int i=1; i<n; i++){
            while(!st1.empty() && heights[st1.top()] >= heights[i]){
                st1.pop();
            }

            if(!st1.empty() && heights[st1.top()] < heights[i]){
                prefix[i] = st1.top();
            }
            if(st1.empty()){
                prefix[i] = -1;
            }
            st1.push(i);
        }

        vector<int> suffix(n);
        stack<int> st2;
        suffix[n-1] = n;
        st2.push(n-1);
        for(int i=n-2; i>=0; i--){
            while(!st2.empty() && heights[st2.top()] >= heights[i]){
                st2.pop();
            }

            if(!st2.empty() && heights[st2.top()] < heights[i]){
                suffix[i] = st2.top();
            }
            if(st2.empty()){
                suffix[i] = n;
            }
            st2.push(i);
        }

        int maxarea = -1;
        for(int i=0; i<n; i++){
            int width = suffix[i] - prefix[i] -1;
            maxarea = max(maxarea, width * heights[i]);
        }
        return maxarea;
    }
};