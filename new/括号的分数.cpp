class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> score;
        int result = 0;
        score.push(0);
        for(int i=0;i<S.length();i++){
            if(S[i]=='(')
                score.push(0);
            else{
                int v = score.top();
                score.pop();
                int w = score.top();
                score.pop();
                score.push(w+max(2*v,1));
            }
        }
        return score.top();
    }
};
