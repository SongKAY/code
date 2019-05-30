class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int,int> m;
        if(bills[0]>5)
            return false;
        m[5] += 1;
        for(int i=1;i<bills.size();i++){
            if(bills[i]==5){
                m[5] += 1;
            }
            else if(bills[i]==10){
                if(!m[5])
                    return false;
                else{
                    m[5] -= 1;
                    m[10] += 1;
                }
            }
            else{
                if(m[10]>=1&&m[5]>=1){
                    m[10] -= 1;
                    m[5] -= 1;
                    m[20] += 1;
                }
                else if(m[5]>=3){
                    m[5] -= 3;
                    m[20] += 1;
                }
                else
                    return false;
            }
        }
        return true;
    }
};
