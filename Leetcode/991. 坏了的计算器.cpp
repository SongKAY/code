class Solution {
public:
    int brokenCalc(int X, int Y) {
        int result = 0;
        while(X<Y){
            if(Y%2==0){
                result += 1;
                Y /= 2;
            }
            else{
                result +=2;
                Y = (Y+1)/2;
            }
        }
        return result + X-Y;
    }
};
