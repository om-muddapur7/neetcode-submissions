class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0;
        int r = n-1;

        int maxArea = 0;

        while(l<r){
            int h = min(heights[l], heights[r]);
            int w = r-l;

            int area = h*w;
            maxArea = max(maxArea, area);

            heights[l]<heights[r] ? l++ : r--;
        }
        return maxArea;
    }
};
