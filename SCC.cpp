/*
      https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_C
      O(V+E)
*/

#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;
const int max1=10005;
int n,m,q,timer=1,c=1;
int flag[max1];
int in[max1],low[max1];
stack<int> s;
bool instack[max1];
vector<int> g[max1];
void dfs(int p){
    in[p]=low[p]=timer++;
    s.push(p);instack[p]=true;
    for(int i:g[p]){
        if(in[i]==-1){
            dfs(i);
            low[p]=min(low[p],low[i]);
        }
        else if(instack[i]){
            low[p]=min(low[p],in[i]);
        }
    }
    if(in[p]==low[p]){
        while(1){
            int curr=s.top();
            s.pop();
            instack[curr]=false;
            flag[curr]=c;
            if(curr==p)break;
        }
        c++;
    }
}
void solve(){
    cin>>n>>m;
    fill_n(in,max1,-1);
    fill_n(low,max1,50000000);
    fill_n(flag,max1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        if(in[i]==-1)dfs(i);
    }
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<((flag[a]==flag[b])&&flag[a]>0?"1":"0")<<"\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
