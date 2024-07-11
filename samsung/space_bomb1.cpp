// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int ans=INT_MIN;
void solve(vector<vector<int>> & board,int isrowsafe,int r, int c, bool used,int coins){
    if(r<0 || c<0 || c>=5){
        ans=max(ans,coins);
        return ;
    }
    if(board[r][c]==1 || board[r][c]==0){
         int newcoins=coins;
        if(board[r][c]==1){
           
            newcoins++;
        }
        if(used){
            isrowsafe--;
        }
        solve(board,isrowsafe,r-1,c,used,newcoins);
         solve(board,isrowsafe,r-1,c+1,used,newcoins);
          solve(board,isrowsafe,r-1,c-1,used,newcoins);
    }
    if(board[r][c]==2){
        if(used && isrowsafe<=0){
            ans=max(ans,coins);
            return;
        }
        else if(used && isrowsafe>0){
            isrowsafe--;
             solve(board,isrowsafe,r-1,c,used,coins);
         solve(board,isrowsafe,r-1,c+1,used,coins);
          solve(board,isrowsafe,r-1,c-1,used,coins);
        }else{
            used=true;
            isrowsafe=4;
             solve(board,isrowsafe,r-1,c,used,coins);
         solve(board,isrowsafe,r-1,c+1,used,coins);
          solve(board,isrowsafe,r-1,c-1,used,coins);
        }
    }
}

int main() {
   int rows;
    cin >> rows;

    vector<vector<int>> board(rows, vector<int>(5));

    // inputting the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> board[i][j];
        }
    }

    int isRowSafe = 0;
    solve(board, isRowSafe, board.size() - 1, 1, false, 0);
    solve(board, isRowSafe, board.size() - 1, 2, false, 0);
    solve(board, isRowSafe, board.size() - 1, 3, false, 0);

    cout << "Max_coins : " << ans << endl;

    return 0;
}