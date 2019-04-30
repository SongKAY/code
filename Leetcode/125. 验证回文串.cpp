class Solution {
public:
    string check(string s){
        for(int i=0;i<s.length();i++){
            if(s[i]>='A'&&s[i]<='Z')
                s[i] += 32;
        }
        return s;
    }
    bool isPalindrome(string s) {
        s = check(s);
        vector<char> v1;
        for(int i=0;i<s.length();i++){
            if(s[i]>='a'&&s[i]<='z')
                v1.push_back(s[i]);
            else if(s[i]-'0'>=0&&s[i]-'0'<=9)
                v1.push_back(s[i]);
        }
        int n = v1.size();
        for(int i=0;i<n/2;i++){
            char s1 = v1[i];
            char s2 = v1[v1.size()-i-1];
            if(s1!=s2)
                return false;
        }
        return true;
    }
};
