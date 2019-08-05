//想好逆序对的个数增加的是左边比右边多的

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
int cnt = 0;

void merge(int l,int mid,int r,vector<int> &a){
    vector<int> temp;
    int left = l;
    int right = mid+1;
    while(left<=mid&&right<=r){
        if(a[left]<=a[right])
            temp.push_back(a[left++]);
        else{
            cnt += mid - left + 1;
            temp.push_back(a[right++]);
        }
    }
    while(left<=mid)
        temp.push_back(a[left++]);
    while(right<=r)
        temp.push_back(a[right++]);
    for(int i=0;i<temp.size();i++){
        a[l+i] = temp[i];
    }
    return;
}

void merge_sort(int l,int r,vector<int> &a){
    if(l>=r)
        return;
    int mid = l + (r-l)/2;
    merge_sort(l,mid,a);
    merge_sort(mid+1,r,a);
    merge(l,mid,r,a);
}

int main(){
    
    int n;
    while(cin>>n){
        vector<int> a(n,0);
        for(int i=0;i<n;i++)
            cin>>a[i];
        cnt = 0;
        merge_sort(0,n-1,a);
        cout<<cnt<<endl;
    }
    return 0;
}
