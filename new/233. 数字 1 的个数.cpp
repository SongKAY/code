class Solution {
public:
    int countDigitOne(int n) {
        long long base = 1;
        int former = 0;
        long long result = 0;
        while(n){
            int round = n / 10;
            int weight = n % 10;
            n /= 10;
            if(weight<1)
                result += round * base;
            else if(weight==1)
                result += round * base + former + 1;
            else
                result += (round+1)*base;
            former += weight * base;
            base *= 10;
        }
        return (int)result;
    }
};
