class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.length()==0||num2.length()==0)
            return "";
        int n = num1.length();
        int m = num2.length();
        string res(n+m,'0');
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int temp = (res[i+j+1]-'0') + (num1[i]-'0') * (num2[j]-'0');
                res[i+j+1] = temp % 10 + '0';
                res[i+j] += temp / 10 ;
            }
        }
        for(int i=0;i<n+m;i++){
            if(res[i]!='0')
                return res.substr(i);
        }
        return "0";
    }
};
