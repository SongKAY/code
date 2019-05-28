class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int n = A.size();
        vector<int> temp;
        if(n<=2)
            return 1;
        int flag= 0;
        for(int i=1;i<n;i++){
            if(A[i]>A[i-1])
                temp.push_back(1);
            else if(A[i]<A[i-1])
                temp.push_back(0);
            else
                temp.push_back(-1);
            if(temp[temp.size()-1]==1||temp[temp.size()-1]==0)
                flag = 1;
        }
        if(!flag)
            return 1;
        int result = 1;
        int i = 1;
        while(i<temp.size()){
            if(temp[i]!=1-temp[i-1]){
                i++;
                continue;
            }
            int cnt = 1;
            while(i<temp.size()&&temp[i]==1-temp[i-1]){
                i++;
                cnt ++;
                result = max(result,cnt);
            }  
        }
        return result+1;
    }
};
