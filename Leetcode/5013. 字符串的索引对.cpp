class Solution {
public:
    static bool cmp (vector<int> a, vector<int> b){
        if(a[0]==b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        vector<vector<int>> result;
        for(int i=0;i<words.size();i++){
            for(int j=0;j+words[i].length()<=text.length();j++){
                if(text[j]!=words[i][0])
                    continue;
                int flag = 0;
                for(int k=j;k<j+words[i].length();k++){
                    if(text[k]!=words[i][k-j]){
                        flag = 1;
                        break;
                    }
                }
                if(!flag)
                    result.push_back(vector<int>{j,j+words[i].length()-1});
            }
        }
        sort(result.begin(),result.end(),cmp);
        return result;
    }
};
