class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int n = nums.size();
        vector<int> ans(n,-1);
        for(int i=0;i<2*n;i++){
            while(!s.empty()&&nums[i%n]>nums[s.top()]){
                ans[s.top()] = nums[i%n];
                s.pop();
            }
            if(i<n)
                s.push(i);
        }
        return ans;
    }
};
