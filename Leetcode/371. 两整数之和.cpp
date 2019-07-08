class Solution {
public:
int getSum(int a, int b) {
    if(b == 0) return a;
    else return getSum(a ^ b, (long long)(a & b) << 1);
    }
};
