class Solution {
public:
    bool reorderedPowerOf2(int N) {
        if(N==0)
            return false;
        vector<int> temp;
        while(N){
            temp.push_back(N%10);
            N/=10;
        }
        sort(temp.begin(),temp.end());
        for(int i=0;i<30;i++){
            int sum = pow(2,i);
            vector<int> cnt;
            while(sum){
                cnt.push_back(sum%10);
                sum/=10;
            }
            if(cnt.size()<temp.size())
                continue;
            else if(cnt.size()>temp.size())
                break;
            sort(cnt.begin(),cnt.end());
            int flag = 0;
            for(int j=0;j<cnt.size();j++){
                if(cnt[j]!=temp[j]){
                    flag=1;
                    break;
                }
            }
            if(!flag)
                return true;
        }
        return false;
    }
};
