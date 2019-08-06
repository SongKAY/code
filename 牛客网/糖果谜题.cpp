#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;

int main(){
    
    string temp;
    getline(cin,temp);
    istringstream scin(temp);
    vector<int> candy;
    int a;
    while(scin>>a){
        candy.push_back(a);
    }
    sort(candy.begin(),candy.end());
    map<int,int> m;
    vector<int> num;
    int n = candy.size();
    for(int i=0;i<n;i++){
        if(m[candy[i]]==0)
            num.push_back(candy[i]);
        m[candy[i]] ++;
    }
    int result = 0;
    for(auto a:num){
        if(m[a]<=(a+1))
            result += (a+1);
        else{
            int tempn = m[a] / (a+1);
            int tempm =(m[a]%(a+1))==0?0:1;
            result += (tempn+tempm) * (a+1);
        }
    }
    cout<<result<<endl;
    return 0;
}
