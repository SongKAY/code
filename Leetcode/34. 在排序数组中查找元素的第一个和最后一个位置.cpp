class Solution {
public:
    int findleft(vector<int>nums,int target){
        int l = 0;
        int r = nums.size()-1;
        while(l<r){
            int mid = l + (r-l)/2;
            if(nums[mid]<target)
                l = mid + 1;
            else if(nums[mid]>=target)
                r = mid;
        }
        if(nums[l]==target)
            return l;
        return -1;
    }
    int findright(vector<int>nums,int target){
        int l = 0;
        int r = nums.size()-1;
        while(l<r){
            int mid = l + (r-l+1)/2;
            if(nums[mid]<=target)
                l = mid;
            else if(nums[mid]>target)
                r = mid-1;
        }
        if(nums[l]==target)
            return l;
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty())
            return vector<int>{-1,-1};
        int l = findleft(nums,target);
        int r = findright(nums,target);
        return vector<int>{l,r};
        
    }
};
