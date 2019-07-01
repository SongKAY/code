class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        A.push_back(K);
        sort(A.begin(),A.end());
        int index = find(A.begin(),A.end(),K) - A.begin();
        if(index < 2)
            return -1;
        int l = 0;
        int r = index - 1;
        int sum = INT_MAX;
        while(l<r){
            int num = A[l] + A[r];
            if(num<K){
                sum = min(K-num,sum);
                l ++;
            }
            if(num>=K)
                r --;
        }
        if(sum!=INT_MAX)
            return K-sum;
        return -1;
    }
};
