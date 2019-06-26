class Solution {
public:
    vector<vector<string>>result;
    vector<string>temp;
    
    bool isPalindrome(string s){
        int i=0,j=s.size()-1;
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    void recursion(string s,int begin,int end){
        if(begin>end){
            result.push_back(temp);
            return;
        }
        for(int i=1;i<=end-begin+1;i++){
            if(isPalindrome(s.substr(begin,i))){
                temp.push_back(s.substr(begin,i));
                recursion(s,begin+i,end);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        recursion(s,0,s.size()-1);
        return result;
    }
};
