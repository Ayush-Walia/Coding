#include <bits/stdc++.h>
#include <ncurses.h>
using namespace std;

class PacmanGame{
  char board[20][80]=
	{
		"*******************************************************************************",
		"*.............................................***.............................*",
		"*.************.............***********..................****   ****...........*",
		"*.************......*......***********..................*         *...........*",
		"*.***...............*......***********..................     .     ...........*",
		"*.************......*......***********..................*         *...........*",
		"*.**................*......***********..................****   ****...........*",
		"*.***********................................................................**",
		"*.***********...............*********............*********...................**",
		"*............**...............*********............*********.................**",
		"*.***********...............*********............*********....................*",
		"*.***********.......*.........................................................*",
		"*...................*..........*************************************..........*",
		"*.***********.......*.......*************************************.............*",
		"*.***********.......*.......................   ***       ***     .............*",
		"*....................*******************.......................******.........*",
		"*.******.............***.............***.......................******.........*",
		"*.*********..........***.***********.***.......................******.........*",
		"*...............***...................................***.....................*",
		"*******************************************************************************",
	};
  char UP ='w';
  char LEFT ='a';
  char DOWN ='s';
  char RIGHT ='d';
  char PACMAN_CHAR='P';
  char GHOST_CHAR='G';
  char dir,d,rgd,bgd,pgd,brgd,rtmp,btmp,ptmp,brtmp,tmpgd;
  pair<int,int> pacman,red_ghost,pink_ghost,blue_ghost,brown_ghost;
  int score=0,gdir,dead=0,moveCount=0;
  public:

void initializeGame(){
    pacman.first=14;
    pacman.second=53;
    red_ghost.first=3;
    red_ghost.second=61;
    pink_ghost.first=4;
    pink_ghost.second=63;
    blue_ghost.first=4;
    blue_ghost.second=59;
    brown_ghost.first=5;
    brown_ghost.second=61;
    board[pacman.first][pacman.second]=PACMAN_CHAR;
    board[red_ghost.first][red_ghost.second]=GHOST_CHAR;
    board[pink_ghost.first][pink_ghost.second]=GHOST_CHAR;
    board[blue_ghost.first][blue_ghost.second]=GHOST_CHAR;
    board[brown_ghost.first][brown_ghost.second]=GHOST_CHAR;
    init_pair(5,COLOR_YELLOW,COLOR_BLACK);
    init_pair(1,COLOR_RED,COLOR_BLACK);
    init_pair(2,COLOR_MAGENTA,COLOR_BLACK);
    init_pair(3,COLOR_CYAN,COLOR_BLACK);
    init_pair(4,COLOR_YELLOW,COLOR_BLACK);
    rgd=UP;
    bgd=LEFT;
    pgd=RIGHT;
    brgd=DOWN;
    rtmp=' ';
    btmp=' ';
    ptmp=' ';
    brtmp=' ';
}

void gameOver(){
        clear();
		printw("███████████████████████████████████████████████████████████████████████████████\n");
		printw("█                       .         .                                           █\n");
		printw("█                      .  .     .  .                                          █\n");
		printw("█                      .   .   .   .                                          █\n");
		printw("█                       .  .   .  .                                           █\n");
		printw("█                       .         .                                           █\n");
		printw("█                      .   O    O  .                                          █\n");
		printw("█                      .     Y     .                                          █\n");
		printw("█                       . ( ___ ) .                                           █\n");
		printw("█                         .     .                                             █\n");
		printw("█                        .  . .  .                                            █\n");
		printw("█                       .   >o<   .                                           █\n");
		printw("█                                                                             █\n");
		printw("█                 GAME OVER!          SCORE: %d                               █\n",score);
		printw("███████████████████████████████████████████████████████████████████████████████\n");
}

void printc(int i,int j){
    if(board[i][j]=='P'){
        attron(A_BOLD);
        attron(COLOR_PAIR(5));
        if(dir==LEFT)
        printw("၁");
        else if(dir==DOWN)
        printw("ဂ");
        else if(dir==UP)
        printw("ပ");
        else
        printw("င");
        attroff(COLOR_PAIR(5));
    }
    else{
    if(i==red_ghost.first && j==red_ghost.second){
        attron(COLOR_PAIR(1));
        printw("Ω");
        attroff(COLOR_PAIR(1));
    }
    else if(i==pink_ghost.first && j==pink_ghost.second){
        attron(COLOR_PAIR(2));
        printw("Ω");
        attroff(COLOR_PAIR(2));
    }
    else if(i==blue_ghost.first && j==blue_ghost.second){
        attron(COLOR_PAIR(3));
        printw("Ω");
        attroff(COLOR_PAIR(3));
    }
    else if(i==brown_ghost.first && j==brown_ghost.second){
        attroff(A_BOLD);
        attron(COLOR_PAIR(4));
        printw("Ω");
        attroff(COLOR_PAIR(4));
        attron(A_BOLD);
    }
    }
}

bool isDead(){
    if(pacman.first==red_ghost.first&&pacman.second==red_ghost.second)
        return true;
    if(pacman.first==pink_ghost.first&&pacman.second==pink_ghost.second)
        return true;
    if(pacman.first==blue_ghost.first&&pacman.second==blue_ghost.second)
        return true;
    if(pacman.first==brown_ghost.first&&pacman.second==brown_ghost.second)
        return true;
    return false;
}

bool canMove(char direction,pair<int,int> p){
    if(p.first==pacman.first&&p.second==pacman.second){
    if(direction==LEFT && board[p.first][p.second-1]=='*')
        return false;
    if(direction==RIGHT && board[p.first][p.second+1]=='*')
        return false;
    if(direction==UP && board[p.first-1][p.second]=='*')
        return false;
    if(direction==DOWN && board[p.first+1][p.second]=='*')
        return false;
    return true;
    }
    else{
    if(direction==LEFT && (board[p.first][p.second-1]=='*' || board[p.first][p.second-1]=='G'))
        return false;
    if(direction==RIGHT && (board[p.first][p.second+1]=='*' || board[p.first][p.second+1]=='G'))
        return false;
    if(direction==UP && (board[p.first-1][p.second]=='*' || board[p.first-1][p.second]=='G'))
        return false;
    if(direction==DOWN && (board[p.first+1][p.second]=='*' || board[p.first+1][p.second]=='G'))
        return false;
    return true;
    }
}

void setDirection(char d){
    if((d==UP ||d==DOWN ||d==LEFT ||d==RIGHT) && canMove(d,pacman)==true)
    dir=d;
}

void eatFood(){
    if(dir==LEFT && board[pacman.first][pacman.second-1]=='.')
        score++;
    if(dir==RIGHT && board[pacman.first][pacman.second+1]=='.')
        score++;
    if(dir==UP && board[pacman.first-1][pacman.second]=='.')
        score++;
    if(dir==DOWN && board[pacman.first+1][pacman.second]=='.')
        score++;
}

void renderGhost(pair<int,int>& ghost,char& gd,char& tmp){
    if(isDead()){
            gameOver();
            getch();
            dead=1;
    }
    if(canMove(gd,ghost)==false)
    while(moveCount<20){
    tmpgd=gd;
    gdir=(rand()%4+1);
    if(gdir==1 && tmpgd!=RIGHT)
    gd=LEFT;
    else if(gdir==2 && tmpgd!=LEFT)
    gd=RIGHT;
    else if(gdir==3 && tmpgd!=DOWN)
    gd=UP;
    else if(gdir==4 && tmpgd!=UP)
    gd=DOWN;
    moveCount++;
    if(canMove(gd,ghost))
    break;
    }
    if(moveCount==19){
        if(tmpgd==LEFT)
        gd=RIGHT;
        else if(tmpgd==RIGHT)
        gd=LEFT;
        else if(tmpgd=UP)
        gd=DOWN;
        else if(tmpgd==DOWN)
        gd=UP;
    }
    if(canMove(gd,ghost)){
    board[ghost.first][ghost.second]=tmp;
    if(gd==LEFT)
        ghost=pair<int,int>(ghost.first,ghost.second-1);
    else if(gd==RIGHT)
        ghost=pair<int,int>(ghost.first,ghost.second+1);
    else if(gd==UP)
        ghost=pair<int,int>(ghost.first-1,ghost.second);
    else if(gd==DOWN)
        ghost=pair<int,int>(ghost.first+1,ghost.second);
    tmp=board[ghost.first][ghost.second];
    board[ghost.first][ghost.second]=GHOST_CHAR;
    }
    moveCount=0;
}

void renderPacman(){
    if(isDead()){
            gameOver();
            getch();
            dead=1;
    }
    if(canMove(dir,pacman)){
    eatFood();
    board[pacman.first][pacman.second]=' ';
    if(dir==LEFT)
        pacman=pair<int,int>(pacman.first,pacman.second-1);
    else if(dir==RIGHT)
        pacman=pair<int,int>(pacman.first,pacman.second+1);
    else if(dir==UP)
        pacman=pair<int,int>(pacman.first-1,pacman.second);
    else if(dir==DOWN)
        pacman=pair<int,int>(pacman.first+1,pacman.second);
    board[pacman.first][pacman.second]=PACMAN_CHAR;
        }
    }

void renderGame(){
    clear();
    for(int i=0;i<20;i++){
      for(int j=0;j<80;j++){
            if(board[i][j]=='*')
            printw("█");
            else if(board[i][j]=='P' || board[i][j]=='G')
            printc(i,j);
            else
            printw("%c",board[i][j]);
        }
      printw("\n");
    }
    printw("\t\t\t\t    Score:%d\n",score);
}

void gameManager(){
    while(!dead || score==924){
    if(dir==UP||dir==DOWN)
        timeout(130);
    else
        timeout(100);
    d=getch();
    setDirection(d);
    renderGhost(red_ghost,rgd,rtmp);
    renderGhost(blue_ghost,bgd,btmp);
    renderGhost(pink_ghost,pgd,ptmp);
    renderGhost(brown_ghost,brgd,brtmp);
    renderPacman();
    renderGame();
    }
}
};

int main(){
    srand(time(NULL));
    setlocale(LC_ALL,"");
    initscr();
    noecho();
    start_color();
    use_default_colors();
    PacmanGame p;
    p.initializeGame();
    p.gameManager();
    return 0;
}
