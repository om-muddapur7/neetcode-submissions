class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size()-1;

        int maxArea = 0;

        while(i<j){
            int ht = min(heights[i], heights[j]);
            int wt = j - i;

            int area = ht * wt;
            maxArea = max(maxArea, area);

            heights[i] < heights[j] ? i++ : j--;
        }

        return maxArea;
    }
};
