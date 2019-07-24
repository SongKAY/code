class Solution {
public:
    bool dfs(vector<int> bucket,vector<int> nums, int sum, int t){
        int n = nums.size();
        if(t==n){
            if(bucket[0]==sum&&bucket[1]==sum&&bucket[2]==sum&&bucket[3]==sum)
                return true;
            return false;
        } 
        for(int i=0;i<4;i++){
            if(bucket[i]+nums[t]>sum)
                continue;
            bucket[i] += nums[t];
            if(dfs(bucket,nums,sum,t+1))
                return true;
            bucket[i] -= nums[t];
        }
        return false;
    }
    bool makesquare(vector<int>& nums) {
        if(nums.size()<4)
            return false;
        int sum = 0;
        int n = nums.size();
        for(auto a:nums){
            sum += a;
        }
        if(sum%4)
            return false;
        sum = sum / 4;
        for(auto i:nums){
            if(i>sum)
                return false;
        }
        vector<int> bucket(4,0);
        return dfs(bucket,nums,sum,0);
    }
};
