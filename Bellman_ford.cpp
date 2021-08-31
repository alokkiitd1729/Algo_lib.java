/*
    find -ve ccycle -     https://cses.fi/problemset/result/2252766/
    
    https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B
    Single Source Shortest Path (Negative Edges)
    O(VE)
*/

#include<bits/stdc++.h>
using namespace std;
const int max1=10000000;
int t,n,m,s;
void solve(){
    cin>>n>>m>>s;
    vector<array<int,3>> e;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        e.push_back({a,b,c});
    }
    int d[n];
    fill_n(d,n,max1);
    int c=0;d[s]=0;
    for(int i=0;i<n;i++){
        int ok=0;
        for(auto x:e){
            if(d[x[0]]!=max1&&d[x[1]]>d[x[0]]+x[2]){
                d[x[1]]=d[x[0]]+x[2];
                ok=1;
            }
        }
        if(ok)c++;
    }
    if(c>=n) cout<<"NEGATIVE CYCLE\n";
    else{
        for(int i=0;i<n;i++)
            if(d[i]>=max1)cout<<"INF\n";
            else cout<<d[i]<<"\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //cin>>t;
    t=1;
    while(t--)solve();
}
