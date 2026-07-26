class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<int> stack;

        heights.push_back(0);

        for(int i=0; i<n+1; i++){ 
           while(!stack.empty() && heights[stack.top()]>= heights[i]){
                int height = heights[stack.top()];
                stack.pop();
                int width = stack.empty() ? i : i - stack.top() -1;
                maxArea = max(maxArea, height*width);

           }
           stack.push(i);
        }

        return maxArea;
    }
};
