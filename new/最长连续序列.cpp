class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> m;
        int result = 0;
        for(int i=0;i<nums.size();i++){
            if(m[nums[i]])
                continue;
            int l = m[nums[i]-1];
            int r = m[nums[i]+1];
            m[nums[i]] = l + r + 1;
            m[nums[i]-l] = l + r + 1;
            m[nums[i]+r] = l + r + 1;
            result = max(result,l+r+1);
        }
        return result;
    }
};
