class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            vector<int> temp = nums2;
            nums2 = nums1;
            nums1 = temp;
        }
        int n = nums1.size();
        int m = nums2.size();
        int left = 0, right = n;
        int halflen = (n+m+1)/2;
        while(left<=right){
            int i = (right + left) / 2;
            int j = halflen - i;
            if(i<right&&nums2[j-1]>nums1[i])
                left = left + 1;
            else if(i>left&&nums1[i-1]>nums2[j])
                right = right - 1;
            else{
                int minleft = 0,maxright = 0;
                if(i==0)
                    minleft = nums2[j-1];
                else if(j==0)
                    minleft = nums1[i-1];
                else{
                    minleft = max(nums1[i-1],nums2[j-1]);
                }
                if((m+n)%2==1)
                    return minleft;
                if(i==n)
                    maxright = nums2[j];
                else if(j==m)
                    maxright = nums1[i];
                else{
                    maxright = min(nums1[i],nums2[j]);
                }
                return (maxright+minleft) / 2.0;
            }
        }
        return 0.0;
    }
};
