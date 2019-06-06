class Solution {
public:
    
    bool check(int s1,int s2,int e1,int e2){
        if(s1>e2||s2>e1)
            return true;
        return false;
    }
    
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int n = A.size();
        vector<pair<int,int>> v1;
        vector<pair<int,int>> v2;
        int sum = 0;
        for(int i=0;i<L;i++)
            sum += A[i];
        v1.push_back(make_pair(0,sum));
        for(int i=1;i<=n-L;i++){
            sum -= A[i-1];
            sum += A[i-1+L];
            v1.push_back(make_pair(i,sum));
        }
        sum = 0;
        for(int i=0;i<M;i++)
            sum += A[i];
        v2.push_back(make_pair(0,sum));
        for(int i=1;i<=n-M;i++){
            sum -= A[i-1];
            sum += A[i-1+M];
            v2.push_back(make_pair(i,sum));
        }
        n = v1.size();
        int m = v2.size();
        int result = 0;
        for(int i=0;i<n;i++){
            int s1 = v1[i].first;
            int e1 = v1[i].first + L - 1;
            for(int j=0;j<m;j++){
                int s2 = v2[j].first;
                int e2 = v2[j].first + M - 1;
                if(check(s1,s2,e1,e2)){
                    result = max(result,v1[i].second + v2[j].second);
                }
            }
        }
        return result;
    }
};
