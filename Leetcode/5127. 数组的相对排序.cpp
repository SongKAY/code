class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> arr1_map;
        for(auto a:arr1){
            arr1_map[a] += 1;
        }
        vector<int> result;
        for(auto a:arr2){
            while(arr1_map[a]){
                result.push_back(a);
                arr1_map[a] -= 1;
            }
        }
        vector<int> temp;
        for(auto a:arr1){
            while(arr1_map[a]){
                arr1_map[a] -= 1;
                temp.push_back(a);
            }
        }
        sort(temp.begin(),temp.end());
        for(auto a:temp)
            result.push_back(a);
        return result;
    }
};
