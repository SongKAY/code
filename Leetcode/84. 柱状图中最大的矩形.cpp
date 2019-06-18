class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty())
            return 0;
        heights.push_back(0);
        stack<int> s;
        int result = 0;
        for(int i=0;i<heights.size();i++){
            while(!s.empty()&&heights[i]<heights[s.top()]){
                int pos = s.top();
                s.pop();
                int height = heights[pos];
                int width = i;
                if(!s.empty())
                    width -= (s.top()+1);
                result = max(result,height*width);
            }
            s.push(i);
        }
        return result;
    }
};
