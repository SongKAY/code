class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        if(A.empty())
            return 0;
        int l = 0;
        int cnt = 0;
        int result = 0;
        for(int i=0;i<A.size();i++){
            if(A[i]==0)
                cnt ++;
            while(l<=i&&cnt>K){
                if(A[l]==0)
                    cnt--;
                l++;
            }
            result = max(i-l+1,result);
        }
        return result;
    }
};
