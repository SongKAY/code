class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            vector<int> temp = nums1;
            nums1 = nums2;
            nums2 = temp;
        }
        int n = nums1.size();
        int m = nums2.size();
        int l = 0;
        int r = n;
        int len = (n+m+1)/2;
        while(l<=r){
            int i = (l+r)/2;
            int j = len - i;
            if(i>l&&nums1[i-1]>nums2[j])
                r = r - 1;
            else if(i<r&&nums2[j-1]>nums1[i])
                l = l + 1;
            else{
                int maxleft=0,minright=0;
                if(i==0)
                    maxleft = nums2[j-1];
                else if(j==0)
                    maxleft = nums1[i-1];
                else{
                    maxleft = max(nums1[i-1],nums2[j-1]);
                }
                if((n+m)%2==1)
                    return maxleft;
                if(i==n)
                    minright = nums2[j];
                else if(j==m)
                    minright = nums1[i];
                else
                    minright = min(nums1[i],nums2[j]);
                return (minright + maxleft) / 2.0;
            }
        }
        return 0.0;
    }
};
