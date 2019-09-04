class Solution {
public:
    int left_bound(vector<int>num,int t){
        int n = num.size();
        int l = 0;
        int r = n-1;
        while(l<=r){
            int mid = l + (r-l) / 2;
            if(num[mid]==t){
                if(mid==0||num[mid-1]!=t)
                    return mid;
                r = mid - 1;
            }
            else if(num[mid]>t)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
    
    int right_bound(vector<int>num,int t){
        int n = num.size();
        int l = 0;
        int r = n-1;
        while(l<=r){
            int mid = l + (r-l) / 2;
            if(num[mid]==t){
                if(mid==num.size()-1||num[mid+1]!=t)
                    return mid;
                l = mid + 1;
            }
            else if(num[mid]>t)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = left_bound(nums,target);
        int right = right_bound(nums,target);
        return vector<int>{left,right};
    }
};
