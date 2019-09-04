class Solution {
public:
    int partition(int l,int r,vector<int>&nums){
        int k = nums[l];
        while(l<r){
            while(l<r&&nums[r]>=k)
                r--;
            nums[l] = nums[r];
            while(l<r&&nums[l]<=k)
                l ++;
            nums[r] = nums[l];
        }
        nums[l] = k;
        return l;
    }
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size()<k)
            return -1;
        int l = 0;
        int n = nums.size();
        int r = n-1;
        int m = n-k;
        while(l<r){
            int mid = partition(l,r,nums);
            if(mid==m)
                return nums[mid];
            else if(mid<=m)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return nums[m];
    }
};
