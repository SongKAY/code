class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> v;
        if(nums.empty())
            return v;
        if(n==1){
            v.push_back(to_string(nums[0]));
            return v;
        }
        int s = 0;
        int e = 0;
        for(int i=0;i<n-1;){
            if(nums[i+1] == nums[i] + 1){
                s = i;
                while(i<n-1&&nums[i+1] == nums[i] + 1){
                    e = i+1;
                    i ++;
                }
                v.push_back(to_string(nums[s])+"->"+to_string(nums[e]));
                i++;
            }
            else{
                v.push_back(to_string(nums[i]));
                i++;
            }
        }
        if(e!=n-1)
            v.push_back(to_string(nums[n-1]));
        return v;
    }
};
