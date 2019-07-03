//别忘了输入为空的情况
class Solution {
public:
    vector<string> result;
    void dfs(map<int,vector<char>> m, vector<int> temp, int t, string s){
        int n = temp.size();
        if(t==n){
            result.push_back(s);
            return;
        }
        int num = temp[t];
        vector<char> c = m[num];
        for(int i=0;i<c.size();i++){
            dfs(m,temp,t+1,s+c[i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return result;
        map<int,vector<char>> m;
        m[2] = {'a','b','c'};
        m[3] = {'d','e','f'};
        m[4] = {'g','h','i'};
        m[5] = {'j','k','l'};
        m[6] = {'m','n','o'};
        m[7] = {'p','q','r','s'};
        m[8] = {'t','u','v'};
        m[9] = {'w','x','y','z'};
        vector<int> temp;
        for(auto i:digits){
            temp.push_back(i-'0');
        }
        dfs(m, temp, 0 , "");
        return result;
    }
};
