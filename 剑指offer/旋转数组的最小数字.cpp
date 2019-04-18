class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.empty())
            return 0;
        int left = 0;
        int right = rotateArray.size()-1;
        while(left<right){
            int mid = left + (right-left) / 2;
            if(rotateArray[right]<rotateArray[mid])
                left = mid + 1;
            else if (rotateArray[right]==rotateArray[mid])
                right = right - 1;
            else
                right = mid;
        }
        return rotateArray[left];
    }
};
