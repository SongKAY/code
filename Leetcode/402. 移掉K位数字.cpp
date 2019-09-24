class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        for(int i=0;i<num.length();i++){
            while(!s.empty()&&num[i]-'0'<s.top()-'0'&&k){
                s.pop();
                k--;
            }
            s.push(num[i]);
        }
        while(k--){
            s.pop();
        }
        string result;
        while(!s.empty()){
            result += s.top();
            s.pop();
        }
        reverse(result.begin(),result.end());
        int i = 0;
        while(i<result.length()){
            if(result[i]!='0')
                break;
            i++;
        }
        if(i==result.length())
            return "0";
        return result.substr(i);
    }
};
