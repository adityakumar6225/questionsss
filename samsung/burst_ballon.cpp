#include <bits/stdc++.h> 

int vector<int> a;
int maxCoins(vector<int>& a)
{
	int n=a.size();
	a.insert(a.begin(),1);
	a.push_back(1);
	

	vector<vector<int>> dp(n+2,vector<int>(n+2,0));
for(int i=n;i>=1;i--){
	for(int j=1;j<=n;j++){
		if(i>j) continue;
		int ans=INT_MIN;
	for(int ind=i;ind<=j;ind++){
		int cost= a[i-1]*a[ind]*a[j+1]+dp[i][ind-1]+dp[ind+1][j];
		ans=max(ans,cost);
	}
	dp[i][j]=ans;
	}
}

	return dp[1][n];
	
}