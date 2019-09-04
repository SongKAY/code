class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int result = 0;
        heights.push_back(0);
        int n = heights.size();
        stack<int> temp;
        for(int i=0;i<n;i++){
            while(!temp.empty()&&heights[i]<heights[temp.top()]){
                int pos = temp.top();
                temp.pop();
                int height = heights[pos];
                int width = i;
                if(!temp.empty())
                    width -= (temp.top()+1);
                result = max(result,height*width);
            }
            temp.push(i);
        }
        return result;
    }
};
