class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        if(A.empty())
            return 0;
        int cnt = 0;
        int n = A.size();
        int m = A[0].size();
        for(int i=0;i<n;i++){
            if(A[i][0])
                continue;
            else{
                for(int j=0;j<m;j++)
                    A[i][j] = 1 - A[i][j];
            }
        }
        for(int j=1;j<m;j++){
            int one = 0;
            int zero = 0;
            for(int i=0;i<n;i++){
                if(A[i][j])
                    one ++;
                else
                    zero ++;
            }
            if(one>zero)
                continue;
            else{
                for(int i=0;i<n;i++)
                    A[i][j] = 1-A[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(A[i][j])
                    cnt += pow(2,m-j-1);
            }
        }
        return cnt;
    }
};
