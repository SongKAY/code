class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> fi;
        if(array.empty())
            return fi;
        int l = 0 ;
        int r = array.size()-1;
        int a = 0;
        int b = 0;
        int result = 99999999;
        while(l<r){
            if(array[l] + array[r]==sum){
                if(array[l]*array[r]<result){
                    a = array[l];
                    b = array[r];
                    result = array[l]*array[r];
                }
                l++;
                r--;
            }
            else{
                while(l<r&&array[l] + array[r]<sum){
                    l++;
                }
                while(l<r&&array[l] + array[r]>sum){
                    r--;
                }
            }
        }
        if(a==0&&b==0)
            return fi;
        fi.push_back(a);
        fi.push_back(b);
        return fi;
    }
};
