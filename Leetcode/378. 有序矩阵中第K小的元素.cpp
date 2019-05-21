class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int l = matrix[0][0];
        int r = matrix[n-1][m-1] + 1;
        while(l<r){
            int mid = l + (r-l)/2;
            int j = m-1;
            int cnt = 0;
            for(int i=0;i<n;i++){
                while(j>=0&&matrix[i][j]>mid)
                    j--;
                cnt += (j+1);
            }
            if(cnt<k)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};
