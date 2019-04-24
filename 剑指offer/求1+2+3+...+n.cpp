class Solution {
public:
    int Sum(int &sum,int n){
        n&&Sum(sum,n-1);
        return sum += n;
    }
    int Sum_Solution(int n) {
        int sum = 0;
        return Sum(sum,n);
    }
};
