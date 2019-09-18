class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
            return false;
        int n = matrix.size();
        int m = matrix[0].size();
        int r = n * m - 1;
        int l = 0;
        while(l<=r){
            int mid = (l+r)/2;
            int pivol = matrix[mid/m][mid%m];
            if(pivol==target)
                return true;
            else if(pivol<target)
                l = mid+1;
            else
                r = mid-1;
        }
        return false;
    }
};
