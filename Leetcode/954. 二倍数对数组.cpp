class Solution {
public:
    static bool cmp(int a,int b){
        return abs(a)<abs(b);
    }
    bool canReorderDoubled(vector<int>& A) {
        map<int,int> m;
        set<int> s;
        vector<int> v;
        for(int i=0;i<A.size();i++){
            s.insert(A[i]);
            m[A[i]] ++;
        }
        set<int>::iterator it = s.begin();
        for(;it!=s.end();it++){
            v.push_back(*it);
        }
        sort(v.begin(),v.end(),cmp);
        for(int i=0;i<v.size();i++){
            if(m[v[i]*2]<m[v[i]])
                return false;
            m[v[i]*2] -= m[v[i]];
        }
        return true;
    }
};
