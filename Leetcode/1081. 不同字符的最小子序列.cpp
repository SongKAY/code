class Solution {
public:
    string smallestSubsequence(string text) {
        map<int,int> visit;
        map<int,int> last;
        for(int i=0;i<text.length();i++){
            int t = text[i] - 'a';
            if(last[t]<i)
                last[t] = i;
        }
        stack<int> s;
        for(int i=0;i<text.length();i++){
            int t = text[i] - 'a';
            if(visit[t]==1)
                continue;
            while(!s.empty()&&last[s.top()]>i&&t<s.top()){
                visit[s.top()] = 0;
                s.pop();
            }
            if(!visit[t]){
                s.push(t);
                visit[t] = 1;
            }
        }
        int u = 0;
        vector<char> v;
        while(!s.empty()){
            char c = s.top() + 'a';
            v.push_back(c);
            s.pop();
        }
        string str;
        for(int i=v.size()-1;i>=0;i--)
            str += v[i];
        return str;
    }
};
