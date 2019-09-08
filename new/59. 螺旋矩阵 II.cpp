class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n,vector<int>(n,0));
        if(n==0)
            return result;
        int cnt = 1;
        int sn = 0;
        int en = n-1;
        int sm = 0;
        int em = n-1;
        while(cnt<=n*n){
            int i = sn;
            int j = sm;
            while(j<=em){
                result[i][j++] = cnt ++;
                if(cnt>n*n)
                    return result;
            }
            i += 1;
            j -= 1;
            while(i<=en){
                result[i++][j] = cnt ++;
                if(cnt>n*n)
                    return result;
            }
            i -= 1;
            j -= 1;
            while(j>=sm){
                result[i][j--] = cnt ++;
                if(cnt>n*n)
                    return result;
            }
            i -= 1;
            j += 1;
            while(i>sn){
                result[i--][j] = cnt ++;
                if(cnt>n*n)
                    return result;
            }
            sn += 1;
            sm += 1;
            em -= 1;
            en -= 1;
        }
        return result;
    }
};
