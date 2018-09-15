#include <iostream>
#include <cstdlib>
using namespace std;

int input;
char arr[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

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
  cout<<"Player 1: X   vs   Player 2: O"<<endl<<endl;
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

int bestMove(int& i,int input){
    int tmp=0;
    if(i>4)
    for(int j=1;j<=9;j++)
        if(arr[j]!='X' && arr[j]!='O'){
            arr[j]='O';
            if(checker(i)==1){
                tmp=1;
                return 1;
                break;
                }
            else
                arr[j]='0'+j;
        }
    if(!tmp&&i>2)
    for(int j=1;j<=9;j++)
        if(arr[j]!='X' && arr[j]!='O'){
            arr[j]='X';
            if(checker(i)==1){
                arr[j]='O';
                tmp=1;
                return 1;
                break;
                }
            else
                 arr[j]='0'+j;
        }
    if(!tmp){
        if(input==5 || arr[5]=='X'){
            int a[4]={1,3,7,9};
            while(1){
            input=a[rand()%4];
            if(arr[input]!='X'&&arr[input]!='O'){
                arr[input]='O';
                tmp=1;
                return 1;
                break;
                }
             else if((a[1]=='X'||a[1]=='O')&&(a[3]=='X'||a[3]=='O')&&(a[7]=='X'||a[7]=='O')&&(a[9]=='X'||a[9]=='O'))
                    tmp=1;
                    break;
            }
        }
        else{
        int a[2];
        if(input==1)
            a[0]=2,a[1]=4;
        else if(input==2)
            a[0]=1,a[1]=3;
        else if(input==3)
            a[0]=2,a[1]=6;
        else if(input==4)
            a[0]=1,a[1]=7;
        else if(input==6)
            a[0]=3,a[1]=9;
        else if(input==7)
            a[0]=4,a[1]=8;
        else if(input==8)
            a[0]=7,a[1]=9;
        else if(input==9)
            a[0]=8,a[1]=6;
        while(1){
        input=a[rand()%2];
        if(arr[input]!='X'&&arr[input]!='O'){
            arr[input]='O';
            tmp=1;
            return 1;
            break;
            }
         else if((a[0]=='X' || a[0]=='O') && (a[1]=='X' || a[1]=='O'))
                tmp=1;
                break;
        }
      }
    }
    if(!tmp)
        return 0;
}

void gameManager(int& i,int mode){
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
    if(arr[input]!='X'&&arr[input]!='O'){
        arr[input]=(((i%2==0)?'X':'O'));
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
    while(1){
    if(i%2==0){
    cout<<"Player "<<"1's(Your Turn)"<<endl;
    cin>>input;
    if(arr[input]!='X'&&arr[input]!='O'){
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
        if(arr[5]!='X'&&arr[5]!='O'){
        arr[5]='O';
        break;
        }
        if(bestMove(i,input)==1){
            break;
        }
        else
        input=rand()%9+1;
        if(arr[input]!='X'&&arr[input]!='O'){
        arr[input]='O';
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
