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
class Solution {
public:
    void mergeSort(vector<int>&nums,int left,int mid,int right){
        vector<int> temp;
        int i = left;
        int j = mid+1;
        while(i<=mid&&j<=right){
            if(nums[i]<nums[j])
                temp.push_back(nums[i++]);
            else
                temp.push_back(nums[j++]);
        }
        while(i<=mid)
            temp.push_back(nums[i++]);
        while(j<=right)
            temp.push_back(nums[j++]);
        for(int i=0;i<temp.size();i++)
            nums[i+left] = temp[i];
    }
    void merge(vector<int>&nums,int left,int right){
        if(left<right){
            int mid = (left+right)/2;
            merge(nums,left,mid);
            merge(nums,mid+1,right);
            mergeSort(nums,left,mid,right);
        }
        return;
    }
    vector<int> sortArray(vector<int>& nums) {
        merge(nums,0,nums.size()-1);
        return nums;
    }
};
