#include<iostream>
using namespace std;

void merge(int arr[],int low,int mid,int high){
    int size1=mid-low+1;
    int size2=high-mid;
    int L[size1],R[size2];
    for(int i=0;i<size1;i++){
        L[i]=arr[low+i];
    }
    for(int j=0;j<size2;j++){
        R[j]=arr[mid+j+1];
    }
    int i=0,j=0,k=low;
    while(i<size1 && j<size2){
        if(L[i]<R[i]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<size1){
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<size2){
        arr[k]=R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int low,int high){
    if(low<high){
        int mid=low+(high-low)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}