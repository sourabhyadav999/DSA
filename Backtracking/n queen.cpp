#include<iostream>
using namespace std;

bool isValid(int board[][15],int i, int j, int n){
    ///checking jth column
    for(int row=0;row<i;row++){
        if(board[row][j]==1) return false;
    }
    ///checking left diagonal
    int x=i;
    int y=j;
    while(x>=0 && y>=0){
        if(board[x][y]==1) return false;
        x--;
        y--;
    }
    ///checking right diagonal
    x=i;
    y=j;
    while(x>=0 && y<n){
        if(board[x][y]==1) return false;
        x--;
        y++;
    }
 
    return true;
}


void solns(int board[][15],int n, int &cnt, int i){
	if(i==n){
		cnt++;
		return;
	}

	for(int j=0;j<n;j++){
        if(isValid(board,i,j,n)){
            ///if current position is valid then place the queen
            board[i][j]=1;
            solns(board,n,cnt,i+1);
            board[i][j]=0;
        }
	}

}

int main() {
	int n; cin>>n;
	int board[15][15]={0};
	int cnt=0;
	solns(board,n,cnt,0);
	cout<<cnt;
	return 0;
}

