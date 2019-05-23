class Solution {
public:
    bool isPalindrome(string s,int l,int r){
        while(l<r){
            if(s[l]!=s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int result = 0;
        int i = 0;
        int j = s.length()-1;
        while(i<j){
            if(s[i]!=s[j]){
                return isPalindrome(s,i+1,j) || isPalindrome(s,i,j-1);
            }
            i++;
            j--;
        }
        return true;
    }
};
