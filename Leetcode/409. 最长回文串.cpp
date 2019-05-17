class Solution {
public:
    int longestPalindrome(string s) {
        if(s.length()==0)
            return 0;
        map<char,int> m;
        set<char> temp;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
            temp.insert(s[i]);
        } 
        int result = 0;
        int flag = 0;
        set<char>::iterator it = temp.begin();
        for(;it!=temp.end();it++){
            char a = *it;
            int t = m[a];
            if(t%2==0){
                result += t;
            }
            else{
                result += t/2*2;
                flag = 1;
            }
        }
        if(flag)
            result += 1;
        return result;
    }
};
