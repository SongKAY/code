class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if(typed.length()<name.length())
            return false;
        int i = 0;
        int j = 0;
        for(;i<name.length()&&j<typed.length();){
            if(typed[j] == name[i]){
                i++;
                j++;
            }
            else{
                if(j==0)
                    return false;
                else{
                    if(typed[j]!=typed[j-1])
                        return false;
                    while(j<typed.length()&&typed[j]==typed[j-1])
                        j++;
                }
            }
        }
        if(i==name.length()){
            while(j<typed.length()){
                if(typed[j]==typed[j-1])
                    j++;
                else
                    break;
            }
            if(j==typed.length())
                return true;
            return false;
        }
        return false;
    }
};
