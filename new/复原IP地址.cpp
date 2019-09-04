class Solution {
public:
    void dfs(vector<string> &result,string s, int begin, int index,string temp){
        if(index==3){
            if(s.length()-begin>3)
                return;
            else if(s[begin]=='0'&&begin!=s.length()-1)
                return;
            int num = stoi(s.substr(begin));
            if(num>=256)
                return;
            temp += '.'+to_string(num);
            string str = temp.substr(1);
            result.push_back(str);
            return;
        }
        for(int i=1;i<=3;i++){
            if(begin+i>=s.length())
                break;
            int num = stoi(s.substr(begin,i));
            if(num>=256)
                continue;
            dfs(result,s,begin+i,index+1,temp+'.'+to_string(num));
            if(s[begin]=='0'&&i==1)
                break;
        }
        return;
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string temp;
        dfs(result,s,0,0,temp);
        return result;
    }
};
