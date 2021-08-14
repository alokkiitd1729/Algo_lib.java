/*
    https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_B
    O(V+E)
*/


#include<bits/stdc++.h>
using namespace std;
const int max1=100001;
int t,n,m,timer=1;
vector<int> g[max1];
int in[max1],low[max1];
vector<pair<int,int>> bridge;
void dfs(int u,int p){
    in[u]=low[u]=timer++;
    for(int v:g[u]){
        if(v==p) continue;
        if(in[v]==-1){
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>in[u]) bridge.push_back({min(u,v),max(u,v)});
        }
        else 
            low[u]=min(low[u],in[v]);
    }
}
void solve(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    fill_n(in,max1,-1);
    for(int i=1;i<=n;i++){
        if(in[i]==-1)dfs(i,-1);
    }
    sort(bridge.begin(),bridge.end());
    for(auto a:bridge)
        cout<<a.first<<" "<<a.second<<"\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //cin>>t;
    t=1;
    while(t--)solve();
}
