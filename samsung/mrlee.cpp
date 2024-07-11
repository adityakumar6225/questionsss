// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int dist[12][12];
int dp[1<<12][12];
 int n,ans;

int dfs(int mask, int pos) {
    if (mask == (1 << n ) - 1) {
        return dist[pos][0];
    }
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }
     int ans = INF;
    for (int i = 0; i <n; i++) {
        if (!(mask & (1 << i)) && dist[pos][i]>0) {
            ans = min(ans, dist[pos][i] + dfs(mask | (1 << i), i));
        }
    }
    return dp[mask][pos] = ans;
}


int main() {
   int tCases;
   cin>>tCases;
   for (int t = 1; t <= tCases; t++){
       
       cin>>n;
       
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>dist[i][j];
        }
       }
       memset(dp, -1, sizeof(dp));
      
       ans=dfs(1,0);
       cout << "#" << t << " " << ans << endl;
       
   }

    return 0;
}