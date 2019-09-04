class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        if(stones.empty())
            return 0;
        int sum = accumulate(stones.begin(),stones.end(),0);
        int n = stones.size();
        vector<int> dp(sum,0);
        for(int i=0;i<n;i++){
            for(int j=sum/2;j>=stones[i];j--){
                dp[j] = max(dp[j],dp[j-stones[i]] + stones[i]);
            }
        }
        return sum - 2 * dp[sum/2];
    }
};
