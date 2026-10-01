class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i < n; i++) {
            
            while(!st.empty() && heights[st.top()] > heights[i]){
                int el=st.top();
                 st.pop();
                int nse = i;
                int pse= st.empty() ? -1 : st.top();

                maxArea=max(maxArea,((nse-pse-1)*heights[el]));
            }
            st.push(i);
        }

        //if some el remains untouched
        while(!st.empty()){
            int el = st.top();
             st.pop();
            int nse=n;
            int pse=st.empty() ? -1 : st.top();
            maxArea=max(maxArea,((nse-pse-1)*heights[el]));
        }

        return maxArea;
    }
};