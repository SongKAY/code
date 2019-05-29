class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s1;
        stack<char> s2;
        for(int i=0;i<S.length();i++){
            if(S[i]=='#'){
                if(!s1.empty())
                    s1.pop();
            }
            else{
                s1.push(S[i]);
            }
        }
        for(int i=0;i<T.length();i++){
            if(T[i]=='#'){
                if(!s2.empty()){
                    s2.pop();
                }
            }
            else{
                    s2.push(T[i]);
            }
        }
        string a1,a2;
        while(!s1.empty()){
            a1 += s1.top();
            s1.pop();
        }
        while(!s2.empty()){
            a2 += s2.top();
            s2.pop();
        }
        if(a1!=a2)
            return false;
        return true;
    }
};
