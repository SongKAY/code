class Solution {
public:
    string addBinary(string a, string b) {
        string s;
        int minlen = min(a.length(),b.length());
        if(b.length()==minlen){
            string temp = a;
            a = b;
            b = temp;
        }
        int flag = 0;//前一位是否进位
        int i = minlen-1;
        int j = b.length()-1;
        for(;i>=0;i--){
            if(a[i]==b[j]){
                if(a[i]=='0'){
                    s += flag?'1':'0';
                    flag = 0;
                }
                else{
                    s += flag?'1':'0';
                    flag  = 1;
                }
            }
            else{
                s += flag?'0':'1';
            }
            j--;
        }
        for(;j>=0;j--){
            if(b[j]=='0'){
                s += flag?'1':'0';
                flag = 0;
            }
            else{
                s += flag?'0':'1';
            }
        }
        if(flag)
            s += '1';
        reverse(s.begin(),s.end());
        return s;
    }
};
