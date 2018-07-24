#include<iostream>
using namespace std;
void merge(int a[],int i1,int j1,int i2,int j2){
    int i=i1,j=i2,k=0,temp[50];
    while(i<=j1 && j<=j2){
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }
    while(i<=j1)
        temp[k++]=a[i++];
    while(j<=j2)
        temp[k++]=a[j++];
    for(i=i1,j=0;i<=j2;i++,j++)
        a[i]=temp[j];
}
void mergesort(int a[],int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,r);
        merge(a,l,mid,mid+1,r);
    }
}
int main(){
    int i,n;
  	cin>>n;
  	int arr[n];
  	for(i=0;i<n;i++)
      cin>>arr[i];
    mergesort(arr,0,n-1);
    cout<<"Sorted Array:"<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
