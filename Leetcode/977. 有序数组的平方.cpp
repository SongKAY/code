class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> result;
        for(int i=0;i<A.size();i++){
            int a = A[i]*A[i];
            result.push_back(a);
        }
        sort(result.begin(),result.end());
        return result;
    }
};
