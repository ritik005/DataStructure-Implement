#include<iostream>
using namespace std;

bool ratinmaze(char maze[10][10],int sol[][10],int i,int j,int m, int n){
    if(i == m && j == n){
        sol[i][j] = 1;
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }

    if(i > m || j > n){
        return false;
    }
    if(maze[i][j] == 'X'){
        return false;
    }
    sol[i][j] = 1;
    bool right = ratinmaze(maze,sol,i,j+1,m,n);
    bool down = ratinmaze(maze,sol,i+1,j,m,n);
    // BackTrack
    sol[i][j] = 0;
    if(right || down){
        return true;
    }
    return false;
}
int main(){
    char maze[10][10] = {
                        "0000",
                        "00X0",
                        "000X",
                        "0X00"
    };
    int sol[10][10] = {0};
    bool ans = ratinmaze(maze,sol,0,0,3,3);
    if(!ans){
        cout << "Path does not exist";
    }
    return 0;
}