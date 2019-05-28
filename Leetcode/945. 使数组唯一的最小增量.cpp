class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int result = 0;
        if(A.size()==0)
            return result;
        sort(A.begin(),A.end());
        int last = -1;
        for(int i=0;i<A.size();i++){
            if(last<A[i])
                last = A[i];
            else{
                result += last - A[i] + 1;
                last ++;
            }
        }
        return result;
    }
};
