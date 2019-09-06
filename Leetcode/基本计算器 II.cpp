class Solution {
public:
    int calculate(string s) {
        char sign = '+';
        stack<int> q;
        int d = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]>='0'&&s[i]<='9')
                d = d * 10 - '0' + s[i];
            if((s[i] < '0' && s[i] != ' ') ||i==s.length()-1){
                if(sign=='+')
                    q.push(d);
                if(sign=='-')
                    q.push(-d);
                if(sign=='*'){
                        int temp = q.top()*d;
                        q.pop();
                        q.push(temp);
                }
                if(sign=='/'){
                        int temp = q.top()/d;
                        q.pop();
                        q.push(temp);
                    }
                sign = s[i];
                d = 0;
            }
        }
        int res = 0;
        while(!q.empty()){
            res += q.top();
            q.pop();
        }
        return res;
    }
};
