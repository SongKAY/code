class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int pos = abs(nums[i]);
            if(nums[pos-1]>0)
                nums[pos-1] *= -1;
            else
                result.push_back(pos);
        }
        return result;
    }
};
