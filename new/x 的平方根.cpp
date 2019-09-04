class Solution {
public:
    int mySqrt(int x) {
        if(x<=1)
            return x;
        long long l = 1L;
        long long r = x/2+1;
        while(l<=r){
            long long mid = l+(r-l)/2;
            if(mid*mid==x){
                return (int)mid;
            }
            else if(mid*mid<x)
                l = mid +1;
            else 
                r = mid - 1;
        }
        return (int)r;
    }
};


class Solution {
public:
    int mySqrt(int x) {
        if(x<=1)
            return x;
        long long cur = x;
        while(cur*cur>x){
            cur = (cur + x/cur) / 2;
        }
        return (int)cur;
    }
};
