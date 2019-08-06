#include <iostream>
#include <string.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.first==b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int main(){
    
    string s;
    while(cin>>s){
        map<char,pair<int,int>> ch;
        map<char,int> flag;
        vector<char> zimu;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(flag[s[i]]){
                ch[s[i]].second = i;
            }
            else{
                ch[s[i]].first = i;
                ch[s[i]].second = i;
                flag[s[i]] = 1;
                zimu.push_back(s[i]);
            }
        }
        vector<pair<int,int>> qujian;
        for(auto c:zimu){
            qujian.push_back(ch[c]);
        }
        sort(qujian.begin(),qujian.end(),cmp);
        vector<int> result;
        int start = qujian[0].first;
        int end = qujian[0].second;
        for(int i=1;i<qujian.size();i++){
            int temps = qujian[i].first;
            int tempe = qujian[i].second;
            if(temps>end){
                result.push_back(end-start+1);
                start = temps;
                end = tempe;
            }
            else{
                end = max(end,tempe);
            }
        }
        result.push_back(end-start+1);
        cout<<result[0];
        for(int i=1;i<result.size();i++)
            cout<<' '<<result[i];
        cout<<endl;
    }
    return 0;
}
