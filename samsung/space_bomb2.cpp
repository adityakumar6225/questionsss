// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int main() {
   int n;
   cin>>n;
  vector<vector<int>>grid(n+1,vector<int>(5));
  for(int i=0;i<=n;i++){
      for(int j=0;j<5;j++){
          cin>>grid[i][j];
      }
  }
  int ans=INT_MIN;
  for(int x=n-1;x>=4;x--){
      vector<vector<int>>grid2=grid;
      for(int j=x;j<=x-4;j++){
          for(int k=0;k<5;k++){
              if(grid[j][k]==2){
                  grid2[j][k]=0;
              }
          }
      }
      vector<vector<int>>dp(n+1,vector<int>(5));
      for(int m=0;m<5;m++){
          if(grid2[0][m]==1) dp[0][m]=1;
      }
      for(int i=1;i<=n;i++){
          for(int j=0;j<5;j++){
              int maxi=dp[i-1][j];
              if(j-1>=0) maxi=max(maxi,dp[i-1][j-1]);
              if(j+1<5) maxi=max(maxi,dp[i-1][j+1]);
              if(grid2[i][j]==1){
                  dp[i][j]=maxi+1;
              }
              if(grid2[i][j]==2){
                  dp[i][j]=0;
              }
              if(grid2[i][j]==0){
                  dp[i][j]=maxi;
              }
          }
          
      }
      ans=max(ans,dp[n-1][2]);
  }
  cout<<ans<<endl;

    return 0;
}