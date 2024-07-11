#include <bits/stdc++.h>
using namespace std;
int n,m,x,y,l;
int mat[1000][1000];
int vis[1000][1000];
int isvalid(int nr,int nc){
	return (nr>=0 && nr<n && nc>=0 && nc<m);
}
bool isleft(int x){
	return (x==1 || x==3 || x==6 || x==7);
}
bool isright(int x){
	return (x==1 || x==3 || x==4 || x==5);
}
bool isup(int x){
	return (x==1 || x==2 || x==4 || x==7);
}
bool isdown(int x){
	return (x==1 || x==2 || x==5 || x==6);
}
int solve(int x,int y,int l){
 queue<pair<pair<int,int>,int>> q;
		q.push({{x,y},l});
		vis[x][y]=1;
		int ans=0;
		while(!q.empty()){
			int r=q.front().first.first;
			int c=q.front().first.second;
			int len=q.front().second;
			q.pop();
			if(len==0) continue;
			ans++;
			if(isvalid(r,c-1) && isleft(mat[r][c]) && isright(mat[r][c-1]) && vis[r][c-1]==0){
				q.push({{r,c-1},len-1});
				vis[r][c-1]=1;
			}
			if(isvalid(r,c+1) && isleft(mat[r][c+1]) && isright(mat[r][c]) && vis[r][c+1]==0){
				q.push({{r,c+1},len-1});
				vis[r][c+1]=1;
			}
			if(isvalid(r-1,c) && isup(mat[r][c]) && isdown(mat[r-1][c]) && vis[r-1][c]==0){
				q.push({{r-1,c},len-1});
				vis[r-1][c]=1;
			}
			if(isvalid(r+1,c) && isdown(mat[r][c]) && isup(mat[r+1][c]) && vis[r+1][c]==0){
				q.push({{r+1,c},len-1});
				vis[r+1][c]=1;
			}
		}
		return ans;
}
int main() {
	int t;
	cin>>t;
	while(t--){
		
		cin>>n>>m>>x>>y>>l;
		
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>mat[i][j];
				 vis[i][j]=0;
			}
			}
		
		
		if(mat[x][y]>0) {
			cout<<solve(x,y,l)<<endl;
		}else{
			cout<<0<<endl;
		}
}
	
}
