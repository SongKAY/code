class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int result = 0;
        if(timeSeries.empty())
            return result;
        sort(timeSeries.begin(),timeSeries.end());
        int pre_end = -1;
        for(auto s:timeSeries){
            if(s<=pre_end){
                result += duration - (pre_end-s) - 1 ;
                pre_end = s + duration - 1;
            }
            else{
                result += duration;
                pre_end = s + duration - 1;
            }
        }
        return result;
    }
};
