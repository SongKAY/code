class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        int n=0;
        if(x!=0&&x!=1){
            for(;pow(x,n)<=bound;n++){
            }
        }
        int m = 0;
        if(y!=0&&y!=1){
            for(;pow(y,m)<=bound;m++){}
        }
        set<int> s;
        vector<int> result;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                int temp = pow(x,i) + pow(y,j);
                if(temp<=bound)
                    s.insert(temp);
            }
        }            
        set<int>::iterator it = s.begin();
        for(;it!=s.end();it++){
            result.push_back(*it);
        }
        return result;
    }
};
