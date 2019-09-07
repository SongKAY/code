class Solution {
public:
    int Sum_Solution(int n) {
        if(n==0)
            return 0;
        return Sum_Solution(n-1) + n;
    }
};
