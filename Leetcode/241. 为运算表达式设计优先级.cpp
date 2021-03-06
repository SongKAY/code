class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        if(input.length()==0)
            return res;
        for(int i=0;i<input.length();i++){
            auto word = input[i];
            if(word=='+'||word=='-'||word=='*'){
                auto r1 = diffWaysToCompute(input.substr(0,i));
                auto r2 = diffWaysToCompute(input.substr(i+1));
                for(auto j:r1){
                    for(auto k:r2){
                        if(word=='+')
                            res.push_back(j+k);
                        else if(word=='-')
                            res.push_back(j-k);
                        else
                            res.push_back(j*k);
                    }
                }
            }
        }
        if(res.empty())
            res.push_back(stoi(input));
        return res;
    }
};
