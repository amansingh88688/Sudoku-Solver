#include <iostream>
#include<cmath>
#include <stdlib.h>  
using namespace std;

bool isSafe(int mat[][9], int i, int j, int no){
    //check for row and column
    for(int k=0; k<9; k++){
        if(mat[k][j]==no || mat[i][k]==no){
            return false;
        } 
    }
    //check for subgrid
    int sx=(i/3)*3;
    int sy=(j/3)*3;

    for(int x=sx; x<sx+3; x++){
        for(int y=sy; y<sy+3; y++){
            if(mat[x][y]==no){
                return false;
            }
        }
    }
    return true;
}


bool solveSudoku(int mat[][9], int i, int j, int n){
    //base case
    if(i==n){
        //print the solution
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout<<mat[i][j]<<" ";
            }
        cout<<endl;
        }
    return true;
    }


    //recursion case
    if(j==n){
        return solveSudoku(mat, i+1, 0, n);
    }
    //skip the prefilled cell
    if(mat[i][j]!=0){
        return solveSudoku(mat, i, j+1, n);
    }
    //cell to be filled
    //try out all possibilities
    for(int no=1; no<=n; no++){
        //whether it is safe to plac  e the number or not
        if(isSafe(mat, i, j, no)){

            mat[i][j]=no;
            bool solveSubproblem=solveSudoku(mat, i, j+1, n);
            if(solveSubproblem==true){
                return true;
            }
        }
    }
    //if no option works, backtracking step
    mat[i][j]=0;
    return false;
}

int main(){
    int n=9;
    int mat[9][9]={0};
    cout<<"Note: Enter 0 if that block is empty."<<endl;
    cout<<"Enter your 9 x 9 matrix :"<<endl<<endl;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin>>mat[i][j];
        }
    }
    cout<<endl;
    cout<<"Yayeee!!!  Your solved Sudoku is here!!!"<<endl<<endl;
    if(!solveSudoku(mat, 0, 0, n)){
        cout<<"Sorry, No Solution exist"<<endl;
        cout<<"Hope you entered a correct matrix"<<endl;
    }


    system("PAUSE");
}