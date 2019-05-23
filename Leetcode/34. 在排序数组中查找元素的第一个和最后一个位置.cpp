class Solution {
public:
    int right_bound(vector<int>& nums,int target){
        int l = 0;
        int r = nums.size()-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid]==target){
                if(mid==nums.size()-1||nums[mid+1]!=target)
                    return mid;
                l = mid + 1;
            }
            else if(nums[mid]<target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
    int left_bound(vector<int>& nums,int target){
        int l = 0;
        int r = nums.size()-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid]==target){
                if(mid==0||nums[mid-1]!=target)
                    return mid;
                r = mid - 1;
            }
            else if(nums[mid]<target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = left_bound(nums,target);
        int right = right_bound(nums,target);
        return vector<int>{left,right};
    }
};
