class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        int currentstart = 0;
        int currentend = 0;
        int cnt = 0;
        while(currentend<T){
            int flag = 0;
            for(auto clip: clips){
                int start = clip[0];
                int end = clip[1];
                if(start<=currentstart&&end>currentend){
                    currentend = end;
                    flag = 1;
                }
            }
            currentstart = currentend;
            if(!flag)
                return -1;
            cnt += 1;
        }
        return cnt;
    }
};
