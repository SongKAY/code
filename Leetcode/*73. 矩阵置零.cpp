class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return;
        set<int> row;
        set<int> col;
        int n =matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        set<int>::iterator it = row.begin();
        for(;it!=row.end();it++){
            matrix[*it] = vector<int>(m,0);
        }
        it = col.begin();
        for(;it!=col.end();it++){
            for(int i=0;i<n;i++){
                matrix[i][*it] = 0;
            }
        }
    }
};
