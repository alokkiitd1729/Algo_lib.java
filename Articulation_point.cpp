/*
    https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_A
    Tarjan low/in idea
    O(V+E)
*/



#include<bits/stdc++.h>
using namespace std;
const int max1=100001;
int t,n,m,timer=1;
vector<int> g[max1];
int in[max1],low[max1];
bool ap[max1];
void dfs(int u,int p){
    in[u]=low[u]=timer++;
    int c=0;
    for(int v:g[u]){
        //if(v==p) continue;
        if(in[v]==-1){
            dfs(v,u);
            c++;
            low[u]=min(low[u],low[v]);
            if(low[v]>=in[u]&&p!=-1) ap[u]=true;
        }
        else 
            low[u]=min(low[u],in[v]);
    }
    if(p==-1&&c>1) ap[u]=true;
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
    dfs(0,-1);
    for(int i=0;i<max1;i++)
        if(ap[i])cout<<i<<"\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //cin>>t;
    t=1;
    while(t--)solve();
}
