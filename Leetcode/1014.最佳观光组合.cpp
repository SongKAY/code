class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        if(A.empty())
            return 0;
        int n = A.size();
        int pre = A[n-1] - (n-1);
        int result = pre;
        for(int i=n-2;i>=0;i--){
            if(pre+A[i]+i>result){
                result = pre+A[i]+i;
            }
            if(pre<A[i]-i)
                pre = A[i]-i;
        }
        return result;
    }
};
