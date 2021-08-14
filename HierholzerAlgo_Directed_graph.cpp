/*
    https://cses.fi/problemset/task/1693/
    
    Finding the Eulerian Path(trail)/Eulerian cycle(Circuit)   
    
    Hierholzer's Algo.   - O(V+E)
*/


#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
vector<int> g[100001];
int in[100001],out[100001];
stack<int> stk;
vector<int> euler,v;
void solve(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        out[x]++;in[y]++;
        g[x].push_back(y);
    }
    for(int i=1;i<=n;i++)if(in[i]!=out[i])v.push_back(i);
    stk.push(1);
    while(!stk.empty()){
        int u=stk.top();
        if(!g[u].empty()){
            int v=g[u].back();
            g[u].pop_back();
            stk.push(v);
        }
        else{
            euler.push_back(u);
            stk.pop();
        }
    }
    /*
        #in each node, the indegree equals the outdegree, or
        
        #in one node, the indegree is one larger than the outdegree, in another node,
        the outdegree is one larger than the indegree, and in all other nodes, the
        indegree equals the outdegree.
 
        In the first case, each Eulerian path is also an Eulerian circuit, and in the
        second case, the graph contains an Eulerian path that begins at the node whose
        outdegree is larger and ends at the node whose indegree is larger.
    */
    if(v.size()<2||v[0]!=1||v[1]!=n||out[1]!=1+in[1]||in[n]!=1+out[n]||euler.size()<=m){cout<<"IMPOSSIBLE";return;}
    reverse(euler.begin(),euler.end());
    for(int u:euler)cout<<u<<" ";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
