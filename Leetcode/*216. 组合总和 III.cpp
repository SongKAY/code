class Solution {
public:
    vector<vector<int>> result;
    void dfs(int pre,int k,int n,int sum,vector<int>temp){
        if(!k){
            if(sum==n)
                result.push_back(temp);
            return;
        }
        for(int i=pre+1;i<=9;i++){
            if(sum+i>n)
                break;
            temp.push_back(i);
            dfs(i,k-1,n,sum+i,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        dfs(0,k,n,0,temp);
        return result;
    }
};
