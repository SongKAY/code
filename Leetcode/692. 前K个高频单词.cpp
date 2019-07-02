class Solution {
public:
    struct node{
      string value;
        int fre = 0;
        bool operator < (const node & a) const{
            if(fre!=a.fre)
                return fre<a.fre;
            else
                return a.value<value;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<node> q;
        map<string,int> m;
        vector<string> temp;
        for(auto i:words){
            if(m[i]==0){
                temp.push_back(i);
            }
            m[i] += 1;
        }
        for(auto i:temp){
            node a;
            a.value = i;
            a.fre = m[i];
            q.push(a);
        }
        vector<string> result;
        while(!q.empty()){
            if(k){
                result.push_back(q.top().value);
                q.pop();
                k--;
            }
            else
                break;
        }
        return result;
    }
};
