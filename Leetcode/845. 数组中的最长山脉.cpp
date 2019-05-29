class Solution {
public:
    int longestMountain(vector<int>& A) {
        if(A.size()<3)
            return 0;
        vector<int> v;
        for(int i=0;i<A.size()-1;i++){
            if(A[i]<A[i+1])
                v.push_back(1);
            else if(A[i]==A[i+1])
                v.push_back(0);
            else
                v.push_back(-1);
        }
        int result = 0;
        int l = -1;
        for(int i=0;i<v.size();){
            if(v[i]==0||v[i]==-1){
                i++;
                continue;
            }
            else{
                int cnt = 0;
                int pre = 1;
                while(i<v.size()){
                    if(v[i]==0){
                        break;
                    }
                    else if(v[i]==-1){
                        if(pre==1)
                            pre = -1;
                        cnt ++;
                    }
                    else{
                        if(pre==1)
                            cnt++;
                        else
                            break;
                    }
                    i++;
                }
                if(pre==-1)
                    result = max(result,cnt);
            }
        }
        if(!result)
            return result;
        return result+1;
    }
};
