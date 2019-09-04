class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int pivol = -1;
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            if(cnt==0){
                pivol = nums[i];
                cnt ++;
            }
            else{
                if(nums[i]==pivol)
                    cnt ++;
                else
                    cnt --;
            }
        }
        return pivol;
    }
};
