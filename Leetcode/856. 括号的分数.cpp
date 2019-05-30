class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<string> s;
        for(int i=0;i<S.length();i++){
            if(S[i]=='('){
                s.push("(");
            }
            else{
                if(!s.empty()&&s.top()=="("){
                    s.pop();
                    s.push("1");
                }
                else{
                    int sum = 0;
                    while(!s.empty()&&s.top()!="("){
                        sum += stoi(s.top());
                        s.pop();
                    }
                    if(!s.empty())
                        s.pop();
                    s.push(to_string(sum * 2));
                }
            }
        }
        int result = 0;
        while(!s.empty()){
            result += stoi(s.top());
            s.pop();
        }
        return result;
    }
};
