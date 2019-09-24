class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n>m){
            vector<int> temp = nums1;
            nums1 = nums2;
            nums2 = temp;
        }
        n = nums1.size();
        m = nums2.size();
        int len = (n + m + 1)/2;
        int l = 0;
        int r = n;
        while(l<=r){
            int l1 =  (r+l)/2;
            int l2 = len - l1;
            if(l1>l&&nums1[l1-1]>nums2[l2])
                r--;
            else if(l1<r&&nums1[l1]<nums2[l2-1])
                l++;
            else{
                int maxleft,minright;
                if(l1==0)
                    maxleft = nums2[l2-1];
                else if(l2==0)
                    maxleft = nums1[l1-1];
                else
                    maxleft = max(nums1[l1-1],nums2[l2-1]);
                if((n+m)%2==1)
                    return maxleft;
                if(l1==n)
                    minright = nums2[l2];
                else if(l2==m)
                    minright = nums1[l1];
                else
                    minright = min(nums1[l1],nums2[l2]);
                return double(minright+maxleft) / double(2.0);
            }
        }
        return 0.0;
    }
};
