class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        map<int,int> m;
        int cnt = 0;
        for(auto a:candies){
            if(m[a]==0){
                m[a] = 1;
                cnt ++;
            }
        }
        int sum = candies.size()/2;
        if(cnt>=sum){
            return sum;
        }
        else
            return cnt;
    }
};
