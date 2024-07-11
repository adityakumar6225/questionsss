// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
   int w_holes;
   cin>>w_holes;
   int n=w_holes*2 +2;
   vector<pair<int,int>> locn(n);
   int sx,sy,dx,dy;
   cin>>sx>>sy>>dx>>dy;
   locn[0].first=sx;
   locn[0].second=sy;
   locn[n-1].first=dx;
   locn[n-1].second=dy;
   vector<vector<int>> cost(n,vector<int>(n,-1));
   for(int i=0;i<w_holes;i++){
       int x1,y1,x2,y2,w;
       cin>>x1>>y1>>x2>>y2>>w;
       locn[2*i+1].first=x1;
       locn[2*i+1].second=y1;
       locn[2*i+2].first=x2;
       locn[2*i+2].second=y2;
       cost[2*i+1][2*i+2]=w;
       cost[2*i+2][2*i+1]=w;
   }
   for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           if(cost[i][j]==-1){
               cost[i][j]=abs(locn[i].first - locn[j].first) +abs(locn[i].second - locn[j].second);
           }
       }
   }
   for(int k=0;k<n;k++){
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        if(i==k||j==k)
                            continue;
                        cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
                    }
                }
            }
  
    cout<<cost[0][n-1]<<endl;

    return 0;
}