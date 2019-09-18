class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> s;
        s.push(num[0]);
        for(int i=1;i<n;i++){
            while(!s.empty()&&s.top()>num[i]&&k){
                k--;
                s.pop();
            }
            s.push(num[i]);
        }
        while(k){
            s.pop();
            k--;
        }
        string result;
        while(!s.empty()){
            result += s.top();
            s.pop();
        }
        reverse(result.begin(),result.end());
        int i=0;
        for(;i<result.length();i++){
            if(result[i]=='0')
                continue;
            else
                break;
        }
        if(i==result.length())
            return "0";
        return result.substr(i);
    }
};
