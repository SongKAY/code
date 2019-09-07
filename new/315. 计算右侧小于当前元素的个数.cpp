class Solution {
public:
    void merge_sort(int l,int mid,int r,vector<pair<int,int>> &pos,vector<int> &result){
        vector<pair<int,int>> temp;
        int i = l;
        int j = mid+1;
        int cnt = 0;
        while(i<=mid&&j<=r){
            if(pos[i].first<=pos[j].first){
                result[pos[i].second] += cnt;
                temp.push_back(pos[i]);
                i++;
            }
            else{
                temp.push_back(pos[j]);
                j++;
                cnt += 1;
            }
        }
        while(i<=mid){
            result[pos[i].second] += cnt;
            temp.push_back(pos[i]);
            i++;
        }
        while(j<=r){
            temp.push_back(pos[j]);
            j++;
        }
        for(int i=0;i<temp.size();i++){
            pos[l+i] = temp[i];
        }
        return;
    }
    void merge(int l,int r,vector<pair<int,int>> &nums,vector<int> &result){
        if(l<r){
            int mid = (l+r)/2;
            merge(l,mid,nums,result);
            merge(mid+1,r,nums,result);
            merge_sort(l,mid,r,nums,result);
        }
        return;
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result(nums.size(),0);
        vector<pair<int,int>> pos;
        if(nums.empty())
            return result;
        for(int i=0;i<nums.size();i++){
            pos.push_back(make_pair(nums[i],i));
        }
        merge(0,nums.size()-1,pos,result);
        return result;
    }
};
