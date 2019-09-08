class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();){
            while(nums[i]>0&&nums[i]<nums.size()&&nums[i]!=i+1){
                if(nums[i]==nums[nums[i]-1])
                    break;
                int temp = nums[i];
                nums[i] = nums[temp-1];
                nums[temp-1] = temp;
            }
            i++;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1)
                return i+1;
        }
        return nums.size()+1;
    }
};
