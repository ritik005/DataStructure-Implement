#include <iostream>
#include <cmath>

using namespace std;
bool canSolve(int mat[][9],int i, int j, int n, int num){
    // row and col check
    for(int k = 0; k < n; k++){
        if(mat[i][k] == num || mat[k][j] == num){
            return false; 
        }
    }
    // grid check
    int rn = sqrt(n);
    int sx = (i/rn)*rn;
    int sy = (j/rn)*rn;
    for(int c = sx; c < sx+rn; c++){
        for(int k = sy; k < sy+rn; k++){
            if(mat[c][k] == num){
                return false;
            }
        }
    }
    return true;
}
bool solveSuduKo(int mat[][9],int i,int j,int n){
    // Base case
    if(i == n){
        // print the matrix
        for(int k = 0; k < n; k++){
            for(int c = 0; c < n ; c++){
                cout << mat[k][c] << "| ";
            }
            cout << endl;
        }
        return true;
    }
    //Case, row ends
    if(j == n){
        return solveSuduKo(mat,i+1,0,n);
    }
    // Skip filled cell
    if(mat[i][j] != 0){
        return solveSuduKo(mat,i,j+1,n);
    }
    // Rec case
    for(int num = 1; num <= n; num++){
        if(canSolve(mat,i,j,n,num)){
            mat[i][j] = num;
            bool couldWeSolve = solveSuduKo(mat,i,j+1,n);
            if(couldWeSolve == true){
                return true;
            }
        }
    }
    // Backtraking
    mat[i][j] = 0;
    return false;

}

int main(){

    int mat[9][9] = 
        {
            {5,3,0,0,7,0,0,0,0},
            {6,0,0,1,9,5,0,0,0},
            {0,9,8,0,0,0,0,6,0},
            {8,0,0,0,6,0,0,0,3},
            {4,0,0,8,0,3,0,0,1},
            {7,0,0,0,2,0,0,0,6},
            {0,6,0,0,0,0,2,8,0},
            {0,0,0,4,1,9,0,0,5},
            {0,0,0,0,8,0,0,7,9}
        };
        solveSuduKo(mat,0,0,9);
        return 0;
}