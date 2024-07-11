#include<bits/stdc++.h>
#define ll long long
#define ld long double

using namespace std;

ll f(ll index,ll k,vector<vector<ll>>& dp,vector<ll>& gate_index,vector<ll>& people,vector<ll>& pref,ll n, ll tot){

    if(dp[index][k]!=-1){
        return dp[index][k];
    }
    if(k==3){
        return dp[index][k]=0;
    }
    if(index==n && k<3){
        return dp[index][k]=1e9;
    }
    if(index+people[k]-1>=n){
        return dp[index][k] = f(index+1,k,dp,gate_index,people,pref,n,tot);
    }else{
        ll poke = 0;
        if(index+people[k]-1<gate_index[k]){
            poke = gate_index[k]*people[k]-(pref[index+people[k]]-pref[index]);
        }
        else if(index>gate_index[k]){
            poke = -gate_index[k]*people[k]+(pref[index+people[k]]-pref[index]);
        }
        else{
            ll a = 0;
            ll b = 0;
            a = gate_index[k]-index;
            b = index+people[k]-1-gate_index[k];
            ll poke1 = a*gate_index[k]-(pref[gate_index[k]]-pref[index]);
            ll poke2 = pref[index+people[k]]-pref[gate_index[k]+1]-b*gate_index[k];
            poke=poke1+poke2;
        }
        ll take = f(index+people[k],k+1,dp,gate_index,people,pref,n,3)+poke;
        ll n_take = f(index+1,k,dp,gate_index,people,pref,n,tot);
        return dp[index][k]=min(take,n_take);
    }
}
int main(){  
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);  
    ll n;
    cin>>n;
    vector<ll>gate_index(3);
    vector<ll>people(3);
    vector<ll>pref(n+1);
    ll sum=0;
    for(ll i=1;i<=n;i++){
        pref[i]=pref[i-1]+i-1;
    }
    for(ll i=0;i<3;i++){
        ll a;
        cin>>a;
        a--;
        gate_index[i]=a;
    }
    for(ll i=0;i<3;i++){
        cin>>people[i];
        sum+=people[i];
    }

    vector<vector<ll>>dp(n+5,vector<ll>(6,-1));
    ll ans = f(0,0,dp,gate_index,people,pref,n,3);
    cout<<ans+sum<<endl;
}