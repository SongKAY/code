class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> result;
        int n = A.size();
        int m = B.size();
        int i = 0;
        int j = 0;
        while(i<n&&j<m){
            int left_A = A[i][0];
            int right_A = A[i][1];
            int left_B = B[j][0];
            int right_B = B[j][1];
            int left = 0;
            int right = -1;
            if(left_A<left_B){
                left = left_B;
            }
            else{
                left = left_A;
            }
            if(right_A<right_B){
                right = right_A;
                i ++;
            }
            else{
                right = right_B;
                j++;
            }
            if(left<=right)
                result.push_back(vector<int>{left,right});
        }
        return result;
    }
};
