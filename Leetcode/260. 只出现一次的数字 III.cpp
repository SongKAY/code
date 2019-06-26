class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int temp = 0;
        vector<int> result;
        for(int i=0;i<nums.size();i++)
            temp ^= nums[i];
        temp = temp & (~temp+1); 
        int a = 0;
        int b = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&temp)
                a^=nums[i];
            else
                b^=nums[i];
        }
        result.push_back(a);
        result.push_back(b);
        return result;
    }
};
