#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min_index=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_index]){
                min_index=j;
            }
        }
        if(min_index!=i){
            swap(arr[i],arr[min_index]);
        }
    }
}
int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    selectionSort(arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}