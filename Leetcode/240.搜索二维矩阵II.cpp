class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
            return false;
        int n = matrix.size();
        int m = matrix[0].size();
        int a = 0;
        int b = m-1;
        while(a<n&&b>=0){
            int t = matrix[a][b];
            if(t==target)
                return true;
            else if(t<target)
                a ++;
            else
                b --;
        }
        return false;
    }
};
