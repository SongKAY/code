class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> s;
        heights.push_back(0);
        int n = heights.size();
        int result = 0;
        for(int i=0;i<n;i++){
            while(!s.empty()&&s.top().first>heights[i]){
                int h = s.top().first;
                int w = i;
                s.pop();
                if(!s.empty())
                    w -= s.top().second+1;
                result = max(result,h*w);
            }
            s.push(make_pair(heights[i],i));
        }
        return result;
    }
};
