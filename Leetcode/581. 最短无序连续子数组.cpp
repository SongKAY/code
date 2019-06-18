class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.empty())
            return 0;
        vector<int> temp = nums;
        sort(nums.begin(),nums.end());
        int start = -1;
        int end = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=temp[i]){
                if(start==-1)
                    start = i;
                else
                    end = i;
            }
        }
        if(start==-1)
            return 0;
        return end - start + 1;
    }
};
