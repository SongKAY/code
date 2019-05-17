class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        int l = 0;
        int r = numbers.size()-1;
        while(l<r){
            int sum = numbers[l] + numbers[r];
            if(sum==target){
                result.push_back(l+1);
                result.push_back(r+1);
                break;
            }
            if(sum<target)
                l++;
            if(sum>target)
                r--;
        }
        return result;
    }
};
