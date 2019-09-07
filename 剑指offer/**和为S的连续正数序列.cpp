class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> result;
        int l = 1;
        int t = 1;
        for(int i=2;i<sum;i++){
            if(t+i<sum){
                t += i;
                continue;
            }
            else{
                while(l<i&&t+i>sum){
                    t -= l;
                    l++;
                }
                t += i;
                if(t==sum){
                    vector<int> temp;
                    for(int j=l;j<=i;j++)
                        temp.push_back(j);
                    result.push_back(temp);
                }
            }
        }
        return result;
    }
};
