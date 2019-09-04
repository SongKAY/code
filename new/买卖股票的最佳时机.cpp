class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int minvalue = prices[0];
        int result = 0;
        for(int i=1;i<prices.size();i++){
            result = max(prices[i]-minvalue,result);
            minvalue = min(minvalue,prices[i]);
        }
        return result;
    }
};
