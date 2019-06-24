class Solution {
public:
    string decodeString(string s) {
        if(s.length()==0)
            return s;
        string result = "";
        stack<char> q;
        for(int i=s.length()-1;i>=0;){
            if(s[i]=='['){
                string temp = "";
                while(!q.empty()&&q.top()!=']'){
                    temp += q.top();
                    q.pop();
                }
                if(!q.empty()&&q.top()==']')
                    q.pop();
                vector<int> tmp;
                i -= 1;
                while(i>=0&&s[i]>='0'&&s[i]<='9'){
                    tmp.push_back(int(s[i]-'0'));
                    i -= 1;
                }
                int cnt = 0;
                for(int j=tmp.size()-1;j>=0;j--)
                    cnt = cnt * 10 + tmp[j];
                string flag = "";
                while(cnt--){
                    flag += temp;
                }
                for(int j = flag.length()-1;j>=0;j--)
                    q.push(flag[j]);
            }
            else{
                q.push(s[i]);
                i -= 1;
            }
        }
        while(!q.empty()){
            result += q.top();
            q.pop();
        }
        return result;
    }
};
