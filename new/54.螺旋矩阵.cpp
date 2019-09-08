class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.empty())
            return result;
        int n = matrix.size();
        int m = matrix[0].size();
        int i = 0;
        int j = 0;
        int sm = 0;
        int em = m-1;
        int sn = 0;
        int en = n-1;
        vector<vector<int>> flag(n,vector<int>(m,0));
        while(result.size()<m*n){
            i = sn;
            j = sm;
            while(j<=em){
                if(flag[i][j])
                    return result;
                flag[i][j] = 1;
                result.push_back(matrix[i][j]);
                j++;
            }
            j -= 1;
            i += 1;
            while(i<=en){
                if(flag[i][j])
                    return result;
                flag[i][j] = 1;
                result.push_back(matrix[i][j]);
                i++;
            }
            i -= 1;
            j -= 1;
            while(j>=sm){
                if(flag[i][j])
                    return result;
                flag[i][j] = 1;
                result.push_back(matrix[i][j]);
                j--;
            }
            j += 1;
            i -= 1;
            while(i>sn){
                if(flag[i][j])
                    return result;
                flag[i][j] = 1;
                result.push_back(matrix[i][j]);
                i--;
            }
            sm += 1;
            em -= 1;
            sn += 1;
            en -= 1;
        }
        return result;
    }
};
