#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main(){
    
    string s;
    getline(cin,s);
    s = s.substr(1);
    s = s.substr(0,s.length()-1);
    istringstream scin(s);
    vector<int> temp;
    int a;
    char c;
    while(scin>>a){
        temp.push_back(a);
        if(scin>>c)
            continue;
        else
            break;
    }
    int n = temp.size();
    vector<int> flag(n,0);
    int start = 0;
    int result = 0;
    while(start>=0&&start<n){
        if(flag[start]){
            result = 1;
            break;
        }
        flag[start] = 1;
        start += temp[start];
    }
    if(result)
        cout<<"false"<<endl;
    else
        cout<<"true"<<endl;
    return 0;
}
