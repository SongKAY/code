class Solution {
public:
    int trans(string s){
        vector<int> temp(26,0);
        for(auto c:s)
            temp[c-'a'] = 1;
        int sum = 0;
        for(int i=25;i>=0;i--){
            if(temp[i])
                sum += pow(2,i);
        }
        return sum;
    }
    int maxProduct(vector<string>& words) {
        if(words.size()<2)
            return 0;
        int result = 0;
        vector<pair<int,int>> temp;
        for(auto s:words){
            temp.push_back(make_pair(trans(s),s.length()));
        }
        for(int i=0;i<temp.size();i++){
            for(int j=i+1;j<temp.size();j++){
                if((temp[i].first&temp[j].first)==0){
                    result = max(result,temp[i].second*temp[j].second);
                }
            }
        }
        return result;
    }
};
