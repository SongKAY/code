class Solution {
public:
    int longestMountain(vector<int>& A) {
        int result = 0;
        if(A.empty())
            return result;
        int i = 0;
        while(i<A.size()){
            int j = i;
            while(j+1<A.size()&&A[j]<A[j+1])
                j++;
            int high = j;
            while(j+1<A.size()&&A[j]>A[j+1])
                j++;
            if(j>high&&i<high)
                result = max(result,j-i+1);
            if(j==i)
                i++;
            else
                i = j;
        }
        return result;
    }
};
