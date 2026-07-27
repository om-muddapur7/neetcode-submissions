class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxi = 0;
        stack<int> st;
        int n = heights.size();

        for(int i=0; i<heights.size(); i++){
            while(!st.empty() && heights[i] <= heights[st.top()]){
                int element = st.top();
                st.pop();

                int nextSmall = i;
                int prevSmall = st.empty() ? -1 : st.top();

                maxi = max(maxi, heights[element] * (nextSmall - prevSmall -1));
            }

            st.push(i);
        }

        while(!st.empty()){
                int element = st.top();
                st.pop();

                int nextSmall = n;
                int prevSmall = st.empty() ? -1 : st.top();

                maxi = max(maxi, heights[element] * (nextSmall - prevSmall -1));
        }

        return maxi;
    }
};
