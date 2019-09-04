class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int l = 0;
        int n = strs.size();
        if(n==0)
            return "";
        string temp = strs[0];
        while(l<temp.length()){
            char t = temp[l];
            for(auto s:strs){
                if(l>=s.length()||s[l]!=t){
                    return temp.substr(0,l);
                }
            }
            l++;
        }
        return temp;
    }
};
