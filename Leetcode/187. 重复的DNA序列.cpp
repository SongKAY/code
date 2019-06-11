class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        if(s.length()<10)
            return result;
        map<string,int> m;
        string temp;
        for(int i=0;i<10;i++)
            temp += s[i];
        m[temp] += 1;
        set<string>tmp;
        for(int i=10;i<s.length();i++){
            temp = temp.substr(1);
            temp += s[i];
            m[temp] += 1;
            tmp.insert(temp);
        }
        set<string>::iterator it = tmp.begin();
        for(;it!=tmp.end();it++){
            if(m[*it]>1)
                result.push_back(*it);
        }
        return result;
    }
};
