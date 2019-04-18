class Solution {
public:
     int  NumberOf1(int n) {
         int cnt = 0;
         int x = n;
         while(x){
             x = x & (x-1);
             cnt ++;
         }
         return cnt;
     }
};
