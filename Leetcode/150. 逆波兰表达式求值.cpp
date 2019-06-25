class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int n = tokens.size();
        for(int i=0;i<n;i++){
            if(tokens[i]=="+"||tokens[i]=="*"||tokens[i]=="-"||tokens[i]=="/"){
                int t2 = s.top();
                s.pop();
                int t1 = s.top();
                s.pop();
                if(tokens[i]=="+")
                    t1 += t2;
                if(tokens[i]=="-")
                    t1 -= t2;
                if(tokens[i]=="*")
                    t1 *= t2;
                if(tokens[i]=="/")
                    t1 /= t2;
                s.push(t1);
            }
            else{
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};
