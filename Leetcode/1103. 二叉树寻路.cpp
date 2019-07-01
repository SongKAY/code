class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int i = 1;
        for(;;i++){
            if(pow(2,i-1)<=label&&pow(2,i)>label)
                break;
        }
        vector<vector<int>> layer;
        int pos = 0;
        for(int t=1;t<=i;t++){
            vector<int> temp;
            for(int j=pow(2,t-1);j<pow(2,t);j++){
                temp.push_back(j);
            }
            if(t%2==0)
                reverse(temp.begin(),temp.end());
            layer.push_back(temp);
            for(int j=0;j<temp.size();j++){
                if(temp[j]==label){
                    pos = j;
                    break;
                }
            }
        }
        vector<int> result;
        result.push_back(label);
        for(int t=i-2;t>=0;t--){
            pos = pos / 2;
            result.push_back(layer[t][pos]);
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
