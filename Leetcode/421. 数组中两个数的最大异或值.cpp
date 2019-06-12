class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxnum = 0;
        int flag = 0;
        for(int i=31;i>=0;i--){
            set<int> hash;
            flag |= (1<<i);
            for(int j=0;j<nums.size();j++)
                hash.insert(flag&nums[j]);
            int temp = maxnum | (1<<i);
            for(int x:hash){
                if(hash.find(x^temp)!=hash.end()){
                    maxnum = temp;
                    break;
                }
            }
        }
        return maxnum;
    }
};
