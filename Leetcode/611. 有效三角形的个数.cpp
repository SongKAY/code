class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size()<3)
            return 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int cnt = 0;
        int r = n-1;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                int k = r;
                int sum = nums[i] + nums[j];
                while(k>j&&nums[k]>=sum){
                    k--;
                }
                if(k!=j)
                    cnt += (k-j);
            }
        }
        return cnt;
    }
};
