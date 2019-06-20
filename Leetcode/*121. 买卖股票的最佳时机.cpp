class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0)
            return 0;
        int result = 0;
        int minx = prices[0];
        for(int i=1;i<n;i++){
            if(prices[i]>minx)
                result = max(result,prices[i]-minx);
            minx = min(minx,prices[i]);
        }
        return result;
    }
};
