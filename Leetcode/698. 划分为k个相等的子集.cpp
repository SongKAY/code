class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        int target=sum/k;
        vector<int> paths(k,0);
        sort(nums.rbegin(),nums.rend());
        return helper(paths,nums,target,0);
    }
    bool helper(vector<int>& paths,vector<int>& nums,int target,int level){
        if(level>=nums.size()) {
            for(auto path:paths){
                if(path!=target) return false;
            }
            return true;
        }
        for(int i=0;i<paths.size();i++){
            if(paths[i]+nums[level]>target) continue;
            paths[i]+=nums[level];
            if(helper(paths,nums,target,level+1)) return true;
            paths[i]-=nums[level];
        }
        return false;
    }
};
