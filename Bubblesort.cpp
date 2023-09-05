#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[],int n){
    bool check=false;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            check=false;
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                check=true;
            }
        }
        if(!check) break;
    }
}

//WhatsApp- +8801867316696

int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    bubbleSort(arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}

//WhatsApp- +8801867316696