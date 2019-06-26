class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> q;
        int cnt = 0;
        for(int i=0;i<S.length();i++){
            if(S[i]=='(')
                q.push(S[i]);
            else{
                if(!q.empty())
                    q.pop();
                else
                    cnt ++;
            }
        }
        while(!q.empty()){
            q.pop();
            cnt++;
        }
        return cnt;
    }
};
