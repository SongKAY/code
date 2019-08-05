#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b){
    return a.second < b.second;
}

int main(){
    
    int n;
    cin>>n;
    vector<pair<int,int>> temp(n);
    for(int i=0;i<n;i++)
        cin>>temp[i].first>>temp[i].second;
    sort(temp.begin(),temp.end(),cmp);
    vector<int> result{temp[0].second-1,temp[0].second};
    for(int i=1;i<n;i++){
        if(temp[i].first==result[result.size()-1])
            result.push_back(temp[i].second);
        else if(temp[i].first > result[result.size()-1]){
            result.push_back(temp[i].second-1);
            result.push_back(temp[i].second);
        }
    }
    cout<<result.size()<<endl;
    return 0;
}
