class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.empty())
            return result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)
                break;
            if(i>0&&nums[i]==nums[i-1])
                continue;
            int target = 0 - nums[i];
            int l = i + 1;
            int r = nums.size()-1;
            while(l<r){
                int temp = nums[l] + nums[r];
                if(temp<target)
                    l ++;
                else if(temp>target)
                    r --;
                else{
                    result.push_back(vector<int>{nums[i],nums[l],nums[r]});
                    while(l+1<r&&nums[l]==nums[l+1]){
                        l ++;
                    }
                    while(l<r-1&&nums[r]==nums[r-1]){
                        r --;
                    }
                    l ++;
                    r --;
                }
            }
        }
        return result;
    }
};
