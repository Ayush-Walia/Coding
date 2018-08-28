#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
char arr[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
void printGrid();
void clear(){
    #ifdef _WIN32
    system("cls");
    #elif defined __linux__
    system("clear");
    #endif
}
int checker(int &i){
  if((arr[1] == arr[2]) && (arr[2] == arr[3]))
    return 1;
  else if((arr[1] == arr[4]) && (arr[4] == arr[7]))
    return 1;
  else if((arr[1] == arr[5]) && (arr[5] == arr[9]))
    return 1;
  else if((arr[2] == arr[5]) && (arr[5] == arr[8]))
    return 1;
  else if((arr[3] == arr[6]) && (arr[6] == arr[9]))
    return 1;
  else if((arr[3] == arr[5]) && (arr[5] == arr[7]))
    return 1;
  else if((arr[4] == arr[5]) && (arr[5] == arr[6]))
    return 1;
  else if((arr[7] == arr[8]) && (arr[8] == arr[9]))
    return 1;
  if(i==9){
    cout<<"It's a tie!!"<<endl;
    exit(0);
  }
}
void printGrid(int& i){
  clear();
  cout<<"Player 1: X\tvs\tPlayer 2: O"<<endl<<endl;
  cout<<"     |     |     "<<endl;
  cout<<"  "<<arr[1]<<"  |  "<<arr[2]<<"  |  "<<arr[3]<<"  "<<endl;
  cout<<"_____|_____|_____"<<endl;
  cout<<"     |     |     "<<endl;
  cout<<"  "<<arr[4]<<"  |  "<<arr[5]<<"  |  "<<arr[6]<<"  "<<endl;
  cout<<"_____|_____|_____"<<endl;
  cout<<"     |     |     "<<endl;
  cout<<"  "<<arr[7]<<"  |  "<<arr[8]<<"  |  "<<arr[9]<<"  "<<endl;
  cout<<"     |     |     "<<endl<<endl;
  i++;
}
void gameManager(int& i,int mode){
    int input;
    printGrid(i);
    if(i>2){
        if(checker(i)==1){
            cout<<"Player "<<((i%2==0)?"2":"1")<<" Won!!"<<endl;
            exit(0);
        }
    }
    if(mode==1){
    while(1){
    cout<<"Player "<<((i%2==0)?"1's":"2's")<<" turn :"<<endl;
    cin>>input;
    if(arr[input]!='X'&&arr[input]!='0'){
        arr[input]=(((i%2==0)?'X':'0'));
        break;
        }
    else{
        clear();
        printGrid(i);
        i--;
        cout<<"Wrong Selection!!"<<endl;
      }
     }
    } else {
    srand(time(NULL));
    while(1){
    if(i%2==0){    
    cout<<"Player "<<"1's(Your Turn)"<<endl;
    cin>>input;
    if(arr[input]!='X'&&arr[input]!='0'){
        arr[input]='X';
        break;
        }
    else{
        clear();
        printGrid(i);
        i--;
        cout<<"Wrong Selection!!"<<endl;
      }
    }else{
        input=rand()%9+1;
    if(arr[input]!='X'&&arr[input]!='0'){
        arr[input]='0';
        break;
       }        
      }
     }  
    }
    gameManager(i,mode);
}
int main()
{
    int choice,mode,i=-1;
    cout<<"Welcome to Tic-Tac-Toe"<<endl<<endl;
    do{
    cout<<"Press 1 to play, 0 to exit: "<<endl;
    cin>>choice;
    switch(choice){
    case 1:
       cout<<"1)Human vs Human"<<endl<<"2)Human vs PC"<<endl;
       cin>>mode;
       gameManager(i,mode);
       break;
    case 0:
        exit(0);
        break;
    default:
        clear();
        cout<<"Invalid Input!!"<<endl<<endl;
    }
    }while(choice!=0);
    return 0;
}
