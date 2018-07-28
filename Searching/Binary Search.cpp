#include<iostream>
using namespace std;
int binarysearch(int arr[],int left,int right,int key){
    if(left<=right){
        int mid=(left+right)/2;
        if(arr[mid]==key)
            return mid;
        if(arr[mid]<key)
            left=mid+1;
        else
            right=mid-1;
    }
    return -1;
 }
int main(){
    int i,n,x;
  	cin>>n;
  	int arr[n];
  	for(i=0;i<n;i++)
      cin>>arr[i];
    cout<<"Enter what to find?"<<endl;
    cin>>x;
    int loc=binarysearch(arr,0,n,x);
    if(loc==-1)
        cout<<x<<" not found!";
    else
        cout<<x<<" found at position "<<loc+1;
   return 0;
}   
