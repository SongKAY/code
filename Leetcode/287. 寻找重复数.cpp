class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int result = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int pos = abs(nums[i]);
            if(nums[pos-1]>0)
                nums[pos-1] *= -1;
            else{
                result = pos;
                break;
            }
        }
        return result;
    }
};
