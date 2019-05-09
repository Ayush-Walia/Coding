#include<bits/stdc++.h>
using namespace std;
#define R 5
#define C 5

bool isSafe(int mat[R][C], int visited[R][C], int x, int y){
	if (mat[x][y] || visited[x][y]==0)
		return false;
	return true;
}

bool isValid(int x, int y){
	if (x < R && y < C && x >= 0 && y >= 0)
		return true;
	return false;
}

void findShortestPath(int mat[R][C], int visited[R][C], int i, int j,int x, int y, int& min_dist, int dist){
	if (i == x && j == y){
		min_dist = min(dist, min_dist);
		return;
	}
	visited[i][j] = 0;

	if (isValid(i + 1, j) && isSafe(mat, visited, i + 1, j))
		findShortestPath(mat, visited, i + 1, j, x, y, min_dist, dist + 1);

	if (isValid(i, j + 1) && isSafe(mat, visited, i, j + 1))
		findShortestPath(mat, visited, i, j + 1, x, y, min_dist, dist + 1);

	if (isValid(i - 1, j) && isSafe(mat, visited, i - 1, j))
		findShortestPath(mat, visited, i - 1, j, x, y, min_dist, dist + 1);

	if (isValid(i, j - 1) && isSafe(mat, visited, i, j - 1))
		findShortestPath(mat, visited, i, j - 1, x, y, min_dist, dist + 1);

	visited[i][j] = 1;
}
void displayMaze(int mat[][C]){
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int mat[R][C]={0},vis[R][C],sx,sy,dx,dy,wc,wx,wy;
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            vis[i][j]=1;
    cout<<"Enter source co-ordinate"<<endl;
    cin>>sx>>sy;
    cout<<"Enter destination co-ordinate"<<endl;
    cin>>dx>>dy;
    cout<<"Enter no. of walls"<<endl;
    cin>>wc;
    cout<<"Enter walls co-ordinate"<<endl;
    while(wc--){
        cin>>wx>>wy;
        mat[wx][wy]=1;
    }
    cout<<"Source pos:"<<sx<<" "<<sy<<"   "<<"Destination pos:"<<dx<<" "<<dy<<endl;
    //displayMaze(mat);
    int min_dist = INT_MAX;
	findShortestPath(mat, vis, sx, sy, dx, dy, min_dist, 0);

	if(min_dist != INT_MAX)
		cout << "The shortest path from source to destination "
				"has length " << min_dist<<endl;
	else
		cout << "Destination can't be reached from given source"<<endl;
}
