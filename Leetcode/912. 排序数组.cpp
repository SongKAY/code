//快排
class Solution {
public:
    void QuickSort(vector<int>&nums,int left,int right){
        if(left>=right)
            return;
        int temp = nums[left];
        int l = left;
        int r = right;
        while(l<r){
            while(l<r&&nums[r]>=temp) //从右边先开始很关键!!!!
                r--;
            while(l<r&&nums[l]<=temp)
                l++;
            if(l<r){
                int t = nums[l];
                nums[l] = nums[r];
                nums[r] = t;
            }
        }
        nums[left] = nums[l];
        nums[l] = temp;
        QuickSort(nums,l+1,right);
        QuickSort(nums,left,l-1);
    }
    vector<int> sortArray(vector<int>& nums) {
        QuickSort(nums,0,nums.size()-1);
        return nums;
    }
};

//归并
