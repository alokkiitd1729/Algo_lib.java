#include <bits/stdc++.h>
using namespace std;
int t,n,m,not_found=1;
stack<int> s;
vector<int> g[100001];
int clr[100001];
void dfs(int u){
    if(!not_found) return;
    for(int v:g[u]){
        if(clr[v]==0){
            clr[v]=1;
            s.push(v);
            dfs(v);
        }
        else if(clr[v]==1&&not_found){
            vector<int> v1;
            v1.push_back(v);
            while(!s.empty()){
                int tt=s.top();s.pop();
                v1.push_back(tt);
                if(tt==v)break;
            }
            reverse(v1.begin(),v1.end());     // Not needed for undirected graph
            cout<<v1.size()<<"\n";
            for(int i=0;i<(int)v1.size();i++)cout<<v1[i]<<" ";
            not_found=0;
            return; 
        }
    }
    clr[u]=2;
    if(!s.empty())s.pop();
}
void solve(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
    }
    fill(clr,clr+100001,0);
    for(int i=1;i<=n;i++){
        if(!clr[i]&&not_found) dfs(i);
    }
    if(not_found) cout<<"IMPOSSIBLE";
}
 
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inputf.txt", "r", stdin);
        freopen("outputf.txt", "w", stdout);
    #endif
        
    ios::sync_with_stdio(false);
    cin.tie(0);
    t=1;
    while(t--) solve();
}
