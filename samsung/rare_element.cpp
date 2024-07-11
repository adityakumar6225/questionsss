// Online C++ compiler to run C++ program online

#include <bits/stdc++.h>
using namespace std;
void bfs(vector<vector<int>> &grid, vector<vector<int>> &temp_dist,int n,int r,int c){
    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,1,0,-1};
    queue<pair<int,int>> q;
     vector<vector<int>> vis(n,vector<int>(n,0));
     q.push({r,c});
     vis[r][c]=1;
     while(!q.empty()){
         int row=q.front().first;
         int col=q.front().second;
         q.pop();
         for(int i=0;i<4;i++){
             int nrow=row+delrow[i];
             int ncol=col+delcol[i];
             if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol]){
                 vis[nrow][ncol]=1;
                 temp_dist[nrow][ncol]=1+temp_dist[row][col];
                 q.push({nrow,ncol});
             }
         }
     }
}

int main() {
   int n,m;
   cin>>n>>m;
   vector<pair<int,int>> rare(m);
   for(int i=0;i<m;i++){
       int x,y;
       cin>>x>>y;
       x--;
       y--;
       rare[i].first=x;
       rare[i].second=y;
   }
   vector<vector<int>> grid(n,vector<int>(n));
   for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           cin>>grid[i][j];
       }
   }
    vector<vector<int>> final_dist(n,vector<int>(n));
   for(int i=0;i<m;i++){
        vector<vector<int>> temp_dist(n,vector<int>(n));
        bfs(grid,temp_dist,n,rare[i].first,rare[i].second);
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                final_dist[j][k]=max(final_dist[j][k],temp_dist[j][k]);
            }
        }
        
   }
   int mini=INT_MAX;
   for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           if(grid[i][j]==1){
               mini=min(mini,final_dist[i][j]);
           }
       }
   }
   cout<<mini<<endl;
    return 0;
}