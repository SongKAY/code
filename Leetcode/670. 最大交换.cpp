class Solution {
public:
    static bool cmp(const char a,const char b){
        return a>b;
    }
    int maximumSwap(int num) {
        string s = to_string(num);
        sort(s.begin(),s.end(),cmp);
        string ori = to_string(num);
        char before,after;
        int flag = 0;
        for(int i=0;i<ori.length();i++){
            if(ori[i]!=s[i]){
                before = ori[i];
                ori[i] = s[i];
                after = s[i];
                flag = 1;
                break;
            }
        }
        if(flag){
            for(int i=ori.length()-1;i>=0;i--){
                if(ori[i]==after){
                    ori[i] = before;
                    break;
                }
            }
        }
        int a = stoi(ori);
        return a;
    }
};
