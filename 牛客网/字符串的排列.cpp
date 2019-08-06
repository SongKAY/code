#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <vector>
#include <set>
using namespace std;

int main(){
    
    string s;
    while(cin>>s){
        set<string> temp;
        sort(s.begin(),s.end());
        do{
            temp.insert(s);
        }while(next_permutation(s.begin(),s.end()));
        set<string>::iterator it = temp.begin();
        cout<<'['<<*it;
        it ++;
        for(it;it!=temp.end();it++){
            cout<<", "<<*it;
        }
        cout<<']'<<endl;
    }
    return 0;
}
