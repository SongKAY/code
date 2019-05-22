class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        if(n==1)
            return stones[0];
        else{
            while(stones.size()>=2){
                n = stones.size();
                sort(stones.begin(),stones.end());
                stones.pop_back();
                stones.pop_back();
                int k = stones[n-1] - stones[n-2];
                if(k==0){
                    continue;
                }
                else{
                    stones.push_back(k);
                }
            }
            if(stones.empty())
                return 0;
            else
                return stones[0];
        }
    }
};
