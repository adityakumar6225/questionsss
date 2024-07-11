#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
using namespace std;

int main(){  
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);  

    ll t1;
    cin>>t1;
    while(t1--){
        ll n,m,t;
        cin>>n>>m>>t;
        t=t/10;
        vector<pair<ll,double>>adj[n+1];
        vector<double>prev(n+1);
        prev[1]=1;
        for(ll i=0;i<m;i++){
            ll a,b;
            double p;
            cin>>a>>b>>p;
            adj[a].pb({b,p});
        }
        for(ll i=1;i<=t;i++){
            vector<double>next(n+1);
            for(ll i=1;i<=n;i++){
                for(auto it:adj[i]){
                    next[it.first]+=prev[i]*it.second;
                }
            }
            prev=next;
        }
        double maxi = 0;
        ll node=-1;
        for(ll i=1;i<=n;i++){
            if(prev[i]>maxi){
                maxi=prev[i];
                node = i;
            }
        }
        if(node==-1){
            cout<<-1<<endl;
        }
        cout<<node<<" "<<maxi<<endl;
    }
    
}