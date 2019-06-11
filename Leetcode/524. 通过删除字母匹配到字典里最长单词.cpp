class Solution {
public:
    static bool cmp(string s1,string s2){
        if(s1.length()!=s2.length())
            return s1.length()>s2.length();
        else
            return s1<s2;
    }
    string findLongestWord(string s, vector<string>& d) {
        map<char,int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]] ++;
        }
        vector<string> result;
        for(int i=0;i<d.size();i++){
            string str = d[i];
            map<char,int> temp = m;
            int flag = 0;
            for(int j=0;j<str.length();j++){
                if(!temp[str[j]]){
                    flag = 1;
                    break;
                }
                temp[str[j]] -= 1;
            }
            if(!flag){
                result.push_back(str);
            }
        }
        sort(result.begin(),result.end(),cmp);
        for(int i=0;i<result.size();i++){
            string str = result[i];
            int j = 0;
            for(int k=0;k<s.length();k++){
                if(s[k]==str[j])
                    j++;
            }
            if(j==str.length())
                return str;
        }
        return "";
    }
};
