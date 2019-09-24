class Solution {
public:
    int calculate(string s) {
        if(s.empty())
            return 0;
        stack<int> q;
        int result = 0;
        char sign = '+';
        int temp = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]>='0'&&s[i]<='9'){
                temp = temp*10 + (s[i]-'0');
            }
            if(s[i]<'0'&&s[i]!=' '||i==s.length()-1){
                if(sign=='+')
                    q.push(temp);
                else if(sign=='-')
                    q.push(-temp);
                else if(sign=='*'){
                    int t = q.top();
                    q.pop();
                    q.push(temp*t);
                }
                else{
                    int t = q.top();
                    q.pop();
                    q.push(t/temp);
                }
                sign = s[i];
                temp = 0;
            }
        }
        while(!q.empty()){
            result += q.top();
            q.pop();
        }
        return result;
    }
};
