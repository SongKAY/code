class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> s;
        if(pushV.size()!=popV.size())
            return false;
        if(pushV.empty())
            return true;
        int n = pushV.size();
        int i = 0;
        int j = 0;
        s.push(pushV[i]);
        i++;
        while(j<n&&i<n){
            if(s.empty()){
                s.push(pushV[i]);
                i++;
            }
            if(i==n)
                break;
            int t = s.top();
            if(t==popV[j]){
                j++;
                s.pop();
            }
            else{
                s.push(pushV[i]);
                i++;
            }
        }
        if(j==n&&s.empty())
            return true;
        else if((j==n&&!s.empty())||(j!=n&&s.empty()))
            return false;
        while(j<n&&!s.empty()){
            int t = s.top();
            s.pop();
            if(t!=popV[j])
                return false;
            j ++;
        }
        return true;
    }
};
