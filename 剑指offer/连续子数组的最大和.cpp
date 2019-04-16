/*不要忘记考虑数组全为负数的情况*/
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int n = array.size();
        int sum = 0;
        int result = 0;
        vector<int> temp(array);
        sort(temp.begin(),temp.end());
        if(temp[temp.size()-1]<0)
            return temp[temp.size()-1];
        for(int i=0;i<n;i++){
            if(sum+array[i]<0)
                sum = 0;
            else
                sum += array[i];
            if(sum>result)
                result = sum;
        }
        return result;
    }
};
