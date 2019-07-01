class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.empty())
            return 0;
        vector<int> result;
        int n = ratings.size();
        result.push_back(1);
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                result.push_back(result.back()+1);
            }
            else
                result.push_back(1);
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1])
                result[i] = max(result[i],result[i+1]+1);
        }
        int fin = 0;
        for(auto a:result)
            fin += a;
        return fin;
    }
};
