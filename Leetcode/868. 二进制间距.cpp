class Solution {
public:
    int binaryGap(int N) {
        if(N==0)
            return 0;
        vector<int> temp;
        while(N){
            temp.push_back(N%2);
            N/=2;
        }
        int l = -1;
        int result = 0;
        for(int i=0;i<temp.size();i++){
            if(temp[i]==0)
                continue;
            else{
                if(l==-1){
                    l = i;
                }
                else{
                    result = max(result, i-l);
                    l = i;
                }
            }
        }
        return result;
    }
};
