/*
    https://cses.fi/problemset/task/1686/
    Tarjan SCC + Condensed graph + Topological sort
    O(V+E)

*/




#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,timer;
vector<int> g[100001],rg[100001];
int in[100001],low[100001],rep[100001],k[100001];
bool instack[100001];
long long f[100001],dp[100001];
stack<int> s;
vector<int> ts;
long long res=0;
void dfs(int u,int p){      // Tarjan's SCC
    in[u]=low[u]=timer++;
    s.push(u); instack[u]=true;
    for(int v:g[u]){
        if(in[v]==-1){
            dfs(v,u);
            low[u]=min(low[u],low[v]);
        }
        else if(instack[v])
            low[u]=min(low[u],in[v]);
    }
    if(low[u]==in[u]){
        cnt++;
        while(1){
            int v=s.top();s.pop();
            f[cnt]+=k[v];
            rep[v]=cnt;
            instack[v]=false;
            if(v==u)break;
        }
        res=max(res,f[cnt]);
        dp[cnt]=f[cnt];
    }
}
void dfs1(int u){   // Topo sort
    in[u]=0;
    for(int v:rg[u]){
        if(in[v]==-1)dfs1(v);
    }
    ts.push_back(u);
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>k[i];
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
    }
    fill_n(in,n+1,-1);
    for(int i=1;i<=n;i++){
        if(in[i]==-1)dfs(i,-1);
    }
    for(int i=1;i<=n;i++){
        for(int u:g[i]){
            if(rep[i]!=rep[u]){
                rg[rep[i]].push_back(rep[u]);   // condensed graph
            }
        }
    }
    fill_n(in,n+1,-1);
    for(int i=1;i<=cnt;i++){
        if(in[i]==-1)dfs1(i);
    }
    reverse(ts.begin(),ts.end());   // topo sort
    for(int u:ts){
        for(int v:rg[u]){
            dp[v]=max(dp[v],dp[u]+f[v]);
            res=max(res,dp[v]);
        }
    }
    cout<<res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
