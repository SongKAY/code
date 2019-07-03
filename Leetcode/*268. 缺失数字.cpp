class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int temp = 0;
        int n = nums.size();
        //sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            temp^=i;
            temp^=nums[i];
        }
        temp ^= n;
        if(temp==n)
            return n;
        else
            return temp;
    }
};
