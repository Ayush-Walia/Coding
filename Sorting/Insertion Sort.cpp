#include <iostream>
using namespace std;
int main(){
	int n,i,j,key,count=0;
  	cin>>n;
  	int a[n];
  	for(i=0;i<n;i++)
      cin>>a[i];
  	for(i=1;i<n;i++){
      key=a[i];
      j=i-1;
      while(j>=0 && a[j]>key){
        a[j+1]=a[j];
        j--;
        count++;
      }
      if(a[j+1]!=key){
      a[j+1]=key;
        count++;
      }
    }
    cout<<"Sorted Array:"<<endl;
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl<<"Number of Shifts: "<<count;
    return 0;
}
