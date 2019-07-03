/*荷兰国旗问题*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int less = -1;
        int more = nums.size();
        int l = 0;
        while(l<more){
            if(nums[l]<1){
                int temp = nums[l];
                nums[l] = nums[++less];
                nums[less] = temp;
                l++;
            }
            else if(nums[l]>1){
                int temp = nums[l];
                nums[l] = nums[--more];
                nums[more] = temp;
            }
            else
                l++;
        }
        return ;
    }
};
