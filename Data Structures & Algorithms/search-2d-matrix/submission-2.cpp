class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int st = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int end = rows * cols - 1;

        while(st <= end){
            int mid = st + (end - st)/2;

            int row = mid/cols;
            int col = mid%cols;

            if(matrix[row][col] > target) end = mid - 1;
            else if(matrix[row][col] < target) st = mid + 1;
            else return true;
        }

        return false;
    }
};
