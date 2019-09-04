归并
class Solution {
public:
    void merge(int l,int mid,int r,vector<int> &nums){
        vector<int> temp;
        int i = l;
        int j = mid+1;
        while(i<=mid&&j<=r){
            if(nums[i]<nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=r){
            temp.push_back(nums[j]);
            j++;
        }
        for(int i=0;i<temp.size();i++){
            nums[i+l] = temp[i];
        }
    }
    void merge_sort(int l,int r,vector<int>&nums){
        if(l>=r)
            return;
        int mid = l + (r-l) / 2;
        merge_sort(l,mid,nums);
        merge_sort(mid+1,r,nums);
        merge(l,mid,r,nums);
    }
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(0,nums.size()-1,nums);
        return nums;
    }
};

快排
class Solution {
public:
    //quick sort
    void quick_sort(int l,int r,vector<int>&nums){
        if(l>r)
            return;
        int i = l;
        int j = r;
        int temp = nums[l];
        while(i<j){
            while(i<j&&nums[j]>=temp)
                j --;
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
    vector<int> sortArray(vector<int>& nums) {
        quick_sort(0,nums.size()-1,nums);
        return nums;
    }
};
