class Solution {
public:
    bool ok(long long mid,vector<int>& nums,int m){
        long long temp = 0;
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            if(temp+nums[i]>mid){
                cnt += 1;
                temp = nums[i];
            }
            else if(temp+nums[i]==mid){
                cnt += 1;
                temp = 0;
            }
            else{
                temp += nums[i];
            }
        }
        if(temp!=0){
            if(temp>mid)
                return false;
            else
                cnt += 1;
        }
        return (cnt<=m)?true:false;
    }
    int splitArray(vector<int>& nums, int m) {
        long long right = 0;
        long long left = 0;
        for(int i=0;i<nums.size();i++){
            right += nums[i];
            left = max((long long)nums[i],left);
        }
        while(left<=right){
            long long mid = left + (right - left) / 2;
            if(ok(mid,nums,m))
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }
};
