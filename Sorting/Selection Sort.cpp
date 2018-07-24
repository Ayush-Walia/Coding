#include <iostream>
using namespace std;
int main(){
  	int n,i,j,temp,index,count=0;
  	cin>>n;
  	int a[n];
  	for(i=0;i<n;i++)
      cin>>a[i];
  	for(i=0;i<n-1;i++){
      index=i;
      for(j=i+1;j<n;j++)
        if(a[j]<a[index])
          index=j;
      if(index!=i){
      temp=a[index];
      a[index]=a[i];
      a[i]=temp;
      count++;
      }
    }
    cout<<"Sorted Array:"<<endl;
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl<<"Number of Swaps: "<<count;
    return 0;
}
