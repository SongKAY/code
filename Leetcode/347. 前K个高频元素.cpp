class Solution {
public:
    struct node{
      int value;
        int fre = 0;
        bool operator < (const node & a) const{
            return fre<a.fre;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<node> q;
        map<int,int> m;
        vector<int> temp;
        for(auto i:nums){
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
        vector<int> result;
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
