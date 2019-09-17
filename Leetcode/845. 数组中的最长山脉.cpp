class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n = A.size();
        int maxlen = 0;
        for(int i=1;i<n;){
            int j = i;
            if(A[j]<=A[j-1])
                i++;
            else{
                int l = j-1;
                while(j<n&&A[j]>A[j-1])
                    j++;
                int mid = j-1;
                while(j<n&&A[j]<A[j-1])
                    j++;
                if(mid+1<j)
                    maxlen = max(maxlen,j-l);
                i = j;
            }
        }
        return maxlen;
    }
};
