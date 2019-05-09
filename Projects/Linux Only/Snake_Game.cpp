#include <iostream>
#include <fstream>
#include <vector>
#include <ncurses.h>
using namespace std;
class SnakeGame{
  char head ='o';
  char tail ='*';
  char food_char ='F';
  char wall='|';
  char UP ='w';
  char LEFT ='a';
  char DOWN ='s';
  char RIGHT ='d';
  char grid[22][90],dir,d;
  vector<pair<int,int>> snake,walls;
  pair<int,int> food;
  int score=0,lvl=1,tx=0,ty=0,tscore=0,playerLoader,temp=0;
  char gameLoader,choice;
  fstream gameSave,playerSave;
  public:

bool loadGame(){
    temp=0;
    gameSave.open("gameData.dat",ios::in);
    playerSave.open("playerData.dat",ios::in);
    if(gameSave.is_open() && playerSave.is_open()){
      while(gameSave.get(gameLoader)){
        if(gameLoader=='\n'){
        tx++;
        ty=0;
        }
        else{
        if(gameLoader==food_char)
            food=pair<int,int>(tx,ty);
        else if(gameLoader==wall)
            walls.push_back(pair<int,int>(tx,ty));
        grid[tx][ty]=gameLoader;
        ty++;
        }
      }
      while(playerSave >> playerLoader){
        if(temp%2==0)
        tx = playerLoader;
        else
        ty = playerLoader;
        temp++;
        if(temp%2==0){
        snake.push_back(pair<int,int>(tx,ty));
        }
        score=playerLoader;
        tscore=score+1;
      }
      if(snake[0].first==snake[1].first && snake[0].second-1==snake[1].second)
         dir=RIGHT;
      else if(snake[0].first==snake[1].first && snake[0].second+1==snake[1].second)
         dir=LEFT;
      else if(snake[0].second==snake[1].second && snake[0].first-1==snake[1].first)
         dir=DOWN;
      else if(snake[0].second==snake[1].second && snake[0].first+1==snake[1].first)
         dir=UP;
      gameSave.close();
      playerSave.close();
      return true;
      }
      else{
        return false;
      }
}

void newGame(){
    for(int i=0;i<22;i++){
      for(int j=0;j<90;j++){
          if(i==0||i==21||j==0||j==89)
            grid[i][j]='#';
          else
            grid[i][j]=' ';
      }
    }
    snake.push_back(pair<int,int>(rand()%10+7,rand()%45+15));
    snake.push_back(pair<int,int>(snake[0].first,snake[0].second-1));
    snake.push_back(pair<int,int>(snake[1].first,snake[1].second-1));
    grid[snake[0].first][snake[0].second]=head;
    grid[snake[1].first][snake[1].second]=tail;
    grid[snake[2].first][snake[2].second]=tail;

    food.first=rand()%17+3;
    food.second=rand()%80+3;
    grid[food.first][food.second]=food_char;
    dir=RIGHT;
}

void initializeGame(){
     auto logo=R"(
    ███████╗███╗   ██╗ █████╗ ██╗  ██╗███████╗     ██████╗  █████╗ ███╗   ███╗███████╗
    ██╔════╝████╗  ██║██╔══██╗██║ ██╔╝██╔════╝    ██╔════╝ ██╔══██╗████╗ ████║██╔════╝
    ███████╗██╔██╗ ██║███████║█████╔╝ █████╗      ██║  ███╗███████║██╔████╔██║█████╗
    ╚════██║██║╚██╗██║██╔══██║██╔═██╗ ██╔══╝      ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝
    ███████║██║ ╚████║██║  ██║██║  ██╗███████╗    ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗
    ╚══════╝╚═╝  ╚═══╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝     ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝
    )";
    printw("%s\n",logo);
    do{
    printw("1)New Game\n2)Load Game\n3)Exit\n");
    refresh();
    choice=getch();
    switch(choice){
    case '1':
       newGame();
       temp=1;
       break;
    case '2':
       if(loadGame()==true){
       temp=1;
       break;
       }
       else{
        clear();
        printw("Save File not Found!!\n\n");
        break;
       }
    case '3':
        endwin();
        exit(0);
        break;
    default:
        clear();
        printw("Invalid Input!!\n\n");
    }
    }while(temp!=1);
}

bool isDead(){
    for(int i=1;i<snake.size();i++)
        if(snake[0]==snake[i])
        return true;
    for(int i=0;i<walls.size();i++)
        if(snake[0]==walls[i])
        return true;
    return false;
}

bool touchBorder(){
    if(snake[0].first==0 || snake[0].first==21 || snake[0].second==0 || snake[0].second==89)
        return true;
    return false;
}

bool eatFood(){
    if(food.first==snake[0].first && food.second==snake[0].second)
        return true;
    return false;
}

void setDirection(char d){
    if((d==UP && dir!=DOWN||d==DOWN && dir!=UP||d==LEFT && dir!=RIGHT||d==RIGHT && dir!=LEFT) &&
touchBorder()==false)
    dir=d;
}

void addWalls(){
    tscore=score;
    while(1){
        tx=rand()%17+3;
        ty=rand()%83+3;
        if(grid[tx][ty]!=head && grid[tx][ty]!=food_char && grid[tx][ty]!=tail && grid[tx][ty]!=wall){
            walls.push_back(pair<int,int>(tx,ty));
            grid[tx][ty]=wall;
            break;
        }
    }
}

void renderSnake(){
    if(eatFood()){
        if(dir==LEFT)
        snake.push_back(pair<int,int>(snake[snake.size()-1].first,snake[snake.size()-1].second+1));
        else if(dir==RIGHT)
        snake.push_back(pair<int,int>(snake[snake.size()-1].first,snake[snake.size()-1].second-1));
        else if(dir==UP)
        snake.push_back(pair<int,int>(snake[snake.size()-1].first-1,snake[snake.size()-1].second));
        else if(dir==DOWN)
        snake.push_back(pair<int,int>(snake[snake.size()-1].first+1,snake[snake.size()-1].second));

        while(1){
        tx=rand()%17+3;
        ty=rand()%80+3;
        if(grid[tx][ty]!=head && grid[tx][ty]!=food_char && grid[tx][ty]!=tail && grid[tx][ty]!=wall){
            food.first=tx;
            food.second=ty;
            grid[food.first][food.second]=food_char;
            score++;
            break;
        }
      }
    }

    grid[snake[snake.size()-1].first][snake[snake.size()-1].second]=' ';
    for(int i=snake.size()-1;i>0;i--){
        snake[i]= snake[i-1];
        grid[snake[i].first][snake[i].second]=tail;
    }

    if(touchBorder()){
    if(dir==LEFT)
        snake[0]=pair<int,int>(snake[0].first,87);
    else if(dir==RIGHT)
        snake[0]=pair<int,int>(snake[0].first,1);
    else if(dir==UP)
        snake[0]=pair<int,int>(20,snake[0].second);
    else if(dir==DOWN)
        snake[0]=pair<int,int>(1,snake[0].second);
    }
    else{
    if(dir==LEFT)
        snake[0]=pair<int,int>(snake[0].first,snake[0].second-1);
    else if(dir==RIGHT)
        snake[0]=pair<int,int>(snake[0].first,snake[0].second+1);
    else if(dir==UP)
        snake[0]=pair<int,int>(snake[0].first-1,snake[0].second);
    else if(dir==DOWN)
        snake[0]=pair<int,int>(snake[0].first+1,snake[0].second);
        }
    grid[snake[0].first][snake[0].second]=head;
}

void renderGame(){
    clear();
    for(int i=0;i<22;i++){
      for(int j=0;j<90;j++){
            if(i==0||i==21||j==0||j==89){
            grid[i][j]='#';
            printw("\u0444");
            }
          else
          printw("%c",grid[i][j]);
      }
      printw("\n");
    }
    printw("\nlevel:%d\t\t\t\t\t\t\t\t\t\tScore:%d\n",lvl,score);
}

void saveGame(){
    fstream gameData("gameData.dat",ios::out);
        for(int i=0;i<22;i++){
          for(int j=0;j<90;j++){
          gameData.put(grid[i][j]);
        }
        gameData.put('\n');
     }
    fstream playerData("playerData.dat",ios::out);
        for(int it=0; it<snake.size(); it++){
            playerData<<snake[it].first;
            playerData<<" ";
            playerData<<snake[it].second;
            playerData<<"\n";
        }
        playerData<<score;
}

void gameManager(){
    while(1){
        if(isDead() || d=='p'){
            if(d=='p')
             saveGame();
            grid[11][40]='G';
            grid[11][41]='a';
            grid[11][42]='m';
            grid[11][43]='e';
            grid[11][44]=' ';
            if(d=='p'){
            grid[11][45]='S';
            grid[11][46]='a';
            grid[11][47]='v';
            grid[11][48]='e';
            grid[11][49]='d';
            grid[11][50]='!';
            }
            else{
            grid[11][45]='O';
            grid[11][46]='v';
            grid[11][47]='e';
            grid[11][48]='r';
            grid[11][49]='!';
            }
            renderGame();
            while(1){
            d=getch();
            if(d!=-1)
                break;
            }
            break;
        }
        if(dir==UP||dir==DOWN)
            timeout(140);
        else
            timeout(110);
        d=getch();
        setDirection(d);
        renderSnake();
        if(score>9)
        lvl=2;
        if(lvl==2 && score>tscore)
            addWalls();
        renderGame();
    }
}
};

int main() {
  srand(time(NULL));
  setlocale(LC_ALL,"");
  initscr();
  noecho();
  SnakeGame s;
  s.initializeGame();
  s.gameManager();
  endwin();
  return 0;
}
