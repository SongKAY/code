class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        stack<int> even;
        stack<int> odd;
        vector<int> result;
        for(auto a:A){
            if(a%2)
                odd.push(a);
            else
                even.push(a);
        }
        for(int i=0;i<A.size();i++){
            if(i%2){
                result.push_back(odd.top());
                odd.pop();
            }
            else{
                result.push_back(even.top());
                even.pop();
            }
        }
        return result;
    }
};
