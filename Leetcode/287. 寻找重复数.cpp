class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            int cnt = 0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]<=mid)
                    cnt++;
            }
            if(cnt>mid){
                r = mid - 1;
            }
            else 
                l = mid + 1;
        }
        return l;
    }
};
