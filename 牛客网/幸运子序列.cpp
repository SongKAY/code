#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int main(){
    
    int n;
    cin>>n;
    stack<int> s;
    int res = 0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        while(s.size()&&s.top()<=x){
            res = max(res,x^s.top());
            s.pop();
        }
        if(s.size())
            res = max(res,x^s.top());
        s.push(x);
    }
    cout<<res<<endl;
    return 0;
}
