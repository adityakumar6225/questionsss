// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int x[20],y[20];
int dist[12][12];
int dp[1<<12][12];
 int n,ans;
void distance() {
    for(int i = 0; i <= n + 1; i++) {
        for(int j = 0; j <= n + 1; j++) {
            dist[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
        }
    }
}
int dfs(int mask, int pos) {
    if (mask == (1 << (n + 1)) - 1) {
        return dist[pos][n + 1];
    }
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }
    int ans = INT_MAX;
    for (int i = 1; i <= n; i++) {
        if (!(mask & (1 << i))) {
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
       cin>>x[n+1]>>y[n+1]>>x[0]>>y[0];
       for(int i=1;i<=n;i++){
           cin>>x[i]>>y[i];
       }
       memset(dp, -1, sizeof(dp));
       distance();
       ans=dfs(1,0);
       cout << "#" << t << " " << ans << endl;
       
   }

    return 0;
}