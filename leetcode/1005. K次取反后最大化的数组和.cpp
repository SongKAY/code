class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        if(A.empty())
            return 0;
        sort(A.begin(),A.end());
        int neg = 0;
        vector<int> v;
        for(int i=0;i<A.size();i++){
            if(A[i]<0){
                neg ++;
                v.push_back(A[i]);
            }
        }
        if(!v.empty())
            sort(v.begin(),v.end());
        int result = 0;
        if(neg==0){
            if(K%2==0){
                for(int i=0;i<A.size();i++)
                    result += A[i];
            }
            else{
                for(int i=1;i<A.size();i++)
                    result += A[i];
                result -= A[0];
            }
        }
        else{
            if(K==neg){
                for(int i=0;i<A.size();i++){
                    if(A[i]<0)
                        result -= A[i];
                    else
                        result += A[i];
                }
            }
            if(K>neg){
                int res = K-neg;
                if(res%2==0){
                    for(int i=0;i<A.size();i++){
                        if(A[i]<0)
                            result -= A[i];
                        else
                            result += A[i];
                    }
                }
                else{
                    for(int i=0;i<A.size();i++){
                        if(A[i]<0){
                            continue;
                        }
                        else{
                            if(-v[v.size()-1]<A[i]){
                                for(int j=0;j<A.size();j++){
                                    if(A[j]<0)
                                        result -= A[j];
                                    else
                                        result += A[j];
                                }
                                result += 2 * v[v.size()-1];
                            }
                            else{
                                for(int j=0;j<A.size();j++){
                                    if(A[j]<0)
                                        result -= A[j];
                                    else
                                        result += A[j];
                                }
                                result -= 2 * A[i];
                            }
                            break;
                        }
                    }
                }
            }
            if(K<neg){
                int cnt = 0;
                while(K--&&cnt<A.size()){
                    A[cnt] = -A[cnt];
                    cnt ++;
                }
                for(int i=0;i<A.size();i++)
                    result += A[i];
            }
        }
        return result;
    }
};
