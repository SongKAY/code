class Solution {
public:
    int maxnum(int start,int end,vector<int>& nums){
        int cmax = nums[start];
        int pmax = max(nums[start],nums[start+1]);
        for(int i=start+2;i<=end;i++){
            int temp = pmax;
            pmax = max((cmax+nums[i]),pmax);
            cmax = temp;
        }
        return pmax;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0],nums[1]);
        return max(maxnum(0,n-2,nums),maxnum(1,n-1,nums));
    }
};
