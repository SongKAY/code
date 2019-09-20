class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.empty())
            return false;
        int n = nums.size();
        unordered_map<int,int> m;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(k!=0&&i>0&&sum%k==0)
                return true;
            if(i>0&&nums[i]==0&&nums[i-1]==0)
                return true;
            if(k!=0)
                sum = sum % k;
            if(m[sum]){
                if(i-m[sum]>0)
                    return true;
            }
            m[sum] = i+1;
        }
        return false;
    }
};

