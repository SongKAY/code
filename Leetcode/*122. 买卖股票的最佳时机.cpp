\\只要第二天比第一天高就出售 贪心
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int result = 0;
        for(int i=1;i<prices.size();i++){
            result += max(prices[i]-prices[i-1],0);
        }
        return result;
    }
};
