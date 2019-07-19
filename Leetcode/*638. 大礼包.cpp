class Solution {
public:
    bool valid(vector<int> gift, vector<int> needs){
        int n = needs.size();
        for(int i=0;i<n;i++)
            if(gift[i] > needs[i])
                return false;
        return true;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = needs.size();
        int minmoney = 0;
        for(int i=0;i<n;i++)
            minmoney += price[i] * needs[i];
        int m = special.size();
        for(int i=0;i<m;i++){
            if(valid(special[i],needs)){
                vector<int> new_needs(n,0);
                for(int j=0;j<n;j++){
                    new_needs[j] = needs[j] - special[i][j];
                }
                int money_temp = shoppingOffers(price,special,new_needs) + special[i].back();
                minmoney = min(minmoney,money_temp);
            }
        }
        return minmoney;
    }
};


