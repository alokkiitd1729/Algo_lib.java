/*
    https://cses.fi/problemset/task/1691/
    
    Finding the Eulerian Path(trail)/Eulerian cycle(Circuit) for Undirected Graph
    
    Hierholzer's Algo.   - O(V+E)
*/


#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
vector<int> g[100001];
int deg[100001];
stack<int> stk;
unordered_set<int> s[100001];
vector<int> euler;
void solve(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        deg[x]++;deg[y]++;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=1;i<=n;i++)if(deg[i]&1)cnt++;
    stk.push(1);
    while(!stk.empty()){
        int u=stk.top();
        if(!g[u].empty()){
            int v=g[u].back();
            if(s[v].find(u)==s[v].end()){
                stk.push(v);
                s[u].insert(v);
            }
            g[u].pop_back();
        }
        else{
            euler.push_back(u);
            stk.pop();
        }
    }
    if((cnt!=0)||euler.size()<=m){cout<<"IMPOSSIBLE";return;}
    for(int u:euler)cout<<u<<" ";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
