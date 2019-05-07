class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if(numRows==0)
            return result;
        for(int i=0;i<numRows;i++){
            vector<int> temp;
            if(i==0){
                temp.push_back(1);
            }
            else{
                temp.push_back(1);
                for(int j=0;j<result[i-1].size()-1;j++){
                    temp.push_back(result[i-1][j] + result[i-1][j+1]);
                }
                temp.push_back(1);
            }
            result.push_back(temp);
        }
        return result;
    }
};
