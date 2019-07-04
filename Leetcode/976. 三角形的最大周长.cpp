class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(),A.end());
        reverse(A.begin(),A.end());
        int i = 0;
        int j = i+1;
        int k = i+2;
        while(k<A.size()){
            if(A[i]<A[j]+A[k]){
                return A[i] + A[j] + A[k];
            }
            else{
                i++;
                j++;
                k++;
            }
        }
        return 0;
    }
};
