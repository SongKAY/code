class Solution {
public:
    bool isvalid(string s){
        int cnt = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
                cnt ++;
            else if(s[i]==')'){
                cnt -= 1;
                if(cnt<0)
                    return false;
            }
        }
        return cnt==0;
    }
    vector<string> removeInvalidParentheses(string s) {
        map<string,int> flag;
        int found = 0;
        queue<string> q;
        q.push(s);
        vector<string> result;
        while(!q.empty()){
            string temp = q.front();
            q.pop();
            if(isvalid(temp)){
                result.push_back(temp);
                found=1;
            }
            if(found)
                continue;
            for(int i=0;i<temp.length();i++){
                if(temp[i]!='('&&temp[i]!=')')
                    continue;
                string t = temp.substr(0,i) + temp.substr(i+1);
                if(!flag[t]){
                    flag[t] = 1;
                    q.push(t);
                }
            }
        }
        return result;
    }
};
