class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int n = customers.size();
        int result = 0;
        if(customers.size()<X){
            for(int i=0;i<n;i++)
                result += customers[i];
            return result;
        }
        else{
            for(int i=0;i<n;i++){
                result += grumpy[i]==0?customers[i]:0;
            }
            int pre = result;
            int temp = result;
            for(int i=0;i<n-X+1;i++){
                for(int j=0;j<X;j++){
                    if(!grumpy[i+j])
                        continue;
                    pre += customers[i+j];
                }
                result = max(pre,result);
                pre = temp;
            }
            return result;
        }
    }
};
