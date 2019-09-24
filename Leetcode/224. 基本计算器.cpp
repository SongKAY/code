class Solution {
public:
    int calculate(string s) {
        if(s.empty())
            return 0;
        int result = 0;
        int sign = 1;
        stack<int> q;
        for(int i=0;i<s.length();){
            if(isdigit(s[i])){
                int j = i;
                while(j<s.length()&&isdigit(s[j]))
                    j++;
                result += stoi(s.substr(i,j-i))*sign;
                i = j;
            }
            else if(s[i]==' '){
                i++;
                continue;
            }
            else if(s[i]=='+'){
                sign = 1;
                i++;
            }
            else if(s[i]=='-'){
                sign = -1;
                i++;
            }
            else if(s[i]=='('){
                q.push(result);
                q.push(sign);
                sign = 1;
                result = 0;
                i++;
            }
            else if(s[i]==')'){
                result = result * q.top();
                q.pop();
                result += q.top();
                q.pop();
                i++;
            }
        }
        return result;
    }
};
