class Solution {
public:
    struct node{
        int val;
        int index;
        bool operator < (const node a) const{
            return index < a.index;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<node> q;
        vector<int> result;
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]] ++;
        }
        for(auto i:m){
            node a;
            a.index = i.second;
            a.val = i.first;
            q.push(a);
        }
        while(k){
            result.push_back(q.top().val);
            q.pop();
            k--;
        }
        return result;
    }
};
