class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int n = pushed.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            while(!s.empty()&&s.top()==popped[cnt]){
                s.pop();
                cnt ++;
            }
            s.push(pushed[i]);
        }
        while(!s.empty()){
            if(s.top()!=popped[cnt])
                return false;
            s.pop();
            cnt++;
        }
        return true;
    }
};
