#include <iostream>
using namespace std;
int main(){
  int a[50],n,i,j,temp,count=0,flag=0;
    cin>>n;
    for(i=0;i<n;i++)
      cin>>a[i];
    for(i=0;i<n;i++,flag=0){
      for(j=0;j<n-i-1;j++){
        if(a[j]>a[j+1]){
          temp=a[j];
          a[j]=a[j+1];
          a[j+1]=temp;
          flag=1;
          count++;
        }
      }
      if(!flag)
        break;
    }
    cout<<"Sorted Array:"<<endl;
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl<<"Number of Swaps: "<<count;
    return 0;
}
