#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int>& vc,int to_find){
    int low=0,high=vc.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(vc[mid]==to_find) return mid;
        if(vc[mid]>to_find) high=mid-1;
        else low=mid+1;
    }
    return -1;
}
int main(){
    int n;cin>>n;
    vector<int> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i];
    sort(vc.begin(),vc.end());
    int to_find;cin>>to_find;
    cout<<binarySearch(vc,to_find);
}
