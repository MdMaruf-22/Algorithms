#include<bits/stdc++.h>
using namespace std;
int UpperBound(vector<int>& vc,int to_find){
    int low=0,high=vc.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(vc[mid]<=to_find) low=mid+1; 
        else high=mid-1;
    }
    return low;
}
int LowerBound(vector<int>& vc,int to_find){
    int low=0,high=vc.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(vc[mid]<to_find) low=mid+1; 
        else high=mid-1;
    }
    return low;
}
int main(){
    int n;cin>>n;
    vector<int> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i];
    sort(vc.begin(),vc.end());
    int to_find;cin>>to_find;
    cout<<UpperBound(vc,to_find);
    cout<<LowerBound(vc,to_find);
}
