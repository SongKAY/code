#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    
    int n;
    cin>>n;
    int result = 0;
    vector<int> people;
    for(int i=0;i<n*2;i++){
        int a;
        cin>>a;
        people.push_back(a);
    }
    vector<int> flag(2*n,1);
    for(int i=0;i<n*2;i++){
        if(flag[i]){
            flag[i] = 0;
            int right = i+1;
            while(right<2*n&&people[i]!=people[right]){
                result += flag[right];
                right ++;
            }
            flag[right] = 0;
        }
    }
    cout<<result<<endl;
    return 0;
}
