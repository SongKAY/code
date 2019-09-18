class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n,-1);
        if(n==0)
            return result;
        stack<pair<int,int>> s;
        s.push(make_pair(nums[0],0));
        for(int i=0;i<2*n;i++){
            while(!s.empty()&&s.top().first<nums[i%n]){
                result[s.top().second] = nums[i%n];
                s.pop();
            }
            s.push(make_pair(nums[i%n],i%n));
        }
        return result;
    }
};
