class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int n = A.size();
        int l = 0;
        int r = 0;
        for(int i=A.size()-1;i>=0;i--){
            int maxless = -1;
            for(int j=i+1;j<n;j++){
                if(A[i]>A[j]&&A[j]>=maxless){
                    l = i;
                    r = j;
                    maxless = A[j];
                }
            }
            if(maxless!=-1)
                break;
        }
        int temp = A[l];
        A[l] = A[r];
        A[r] = temp;
        return A;
    }
};
