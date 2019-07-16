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


/*还是快排吧*/
class Solution {
public:
    void quick_sort(int l,int r,vector<int>&nums){
        if(l>r)
            return;
        int i = l;
        int j = r;
        int temp = nums[l];
        while(i<j){
            while(i<j&&nums[j]>=temp)
                j--;
            while(i<j&&nums[i]<=temp)
                i++;
            if(i<j){
                int t = nums[i];
                nums[i] = nums[j];
                nums[j] = t;
            }
        }
        nums[l] = nums[i];
        nums[i] = temp;
        quick_sort(l,i-1,nums);
        quick_sort(i+1,r,nums);
    }
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        quick_sort(0,n-1,nums);
    }
};
