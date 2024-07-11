//Time Complexity O(n*n*k)
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
using namespace std;

ll f(ll index,ll prev,ll count,vector<ll>& arr,vector<vector<vector<ll>>>& dp,ll k){

    if(dp[index][prev][count]!=-1){
        return dp[index][prev][count];
    }
    if(count==k){
        return dp[index][prev][count]=0;
    }
    if(index==0 && k!=count){
        //Take any big number
        return dp[index][prev][count]=1e15;
    }
    ll take = f(index-1,index,count+1,arr,dp,k)+(prev-index)*arr[index-1];
    ll n_take = f(index-1,prev,count,arr,dp,k);
    return dp[index][prev][count]=min(take,n_take);
}
int main(){  
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);  

    ll n;
    cin>>n;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    ll k;
    cin>>k;
    sort(arr.begin(),arr.end());
    vector<vector<vector<ll>>>dp(n+3,vector<vector<ll>>(n+3,vector<ll>(k+1,-1)));
    ll ans = f(n,n+1,0,arr,dp,k);
    cout<<ans<<endl;
}