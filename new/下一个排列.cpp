class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.empty())
            return;
        int n = nums.size()-1;
        int i=n;
        int flag = 0;
        for(;i>=1;i--){
            if(nums[i]>nums[i-1]){
                break;
            }
        }
        if(i<1){
            sort(nums.begin(),nums.end());
            return;
        }
        else{
            int j = n;
            for(;j>=i;j--){
                if(nums[j]>nums[i-1]){
                    int temp = nums[j];
                    nums[j] = nums[i-1];
                    nums[i-1] = temp;
                    break;
                }
            }
            sort(nums.begin()+i,nums.end());
            return;
        }
    }
};
