// https://csacademy.com/contest/archive/task/and-closure/statement/
//https://csacademy.com/blog/fast-fourier-transform-and-variations-of-it
// https://codeforces.com/blog/entry/76177#comment-682763
########################################################################  short clean for -        AND/OR/XOR
/*
  problem - find smallest size of subset such that their OR/AND/XOR = given value.
   we can solve it using same techinique O(Nlog(A_i)log(log(A_i)))... we can binary search on the size 
   also size will be bounded by log(A_i). see this blog -    https://codeforces.com/blog/entry/76177#comment-682763
 
 (2).  Find no of ways to choose tuple of size K (or of at most size K - not this will be a diff problem)
   such that their AND/OR/XOR is equal to a given value.
   Be careful for finding tuple of size EXACTLY K if zero is present in the array.
   
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz (1 << 20)
#define maxN (sz + 11)
#define mod 1000000007
int AND=0,OR=1,XOR=2;
ll n, x,cnt=0;
vector<ll> a(maxN,0);
ll poww(ll a, ll b) {
    if(b<=0) return 1;
    ll c=poww(a,b/2); c*=c;c%=mod;
    return b%2?c*a%mod:c;
}
void FST(bool inv,int op){
    for(int step=1;2*step<=sz;step*=2){
        for(int i=0;i<sz;i+=2*step){
            for(int j=i;j<i+step;j++){
                ll &u=a[j],&v=a[j+step];
                if(op==AND)tie(u,v)=inv?make_pair((v-u+mod)%mod,u):make_pair(v,(u+v)%mod);//AND
                if(op==OR)tie(u,v)=inv?make_pair(v,(u-v+mod)%mod):make_pair((u+v)%mod,v);//OR
                if(op==XOR)tie(u,v)=make_pair((u+v)%mod,(u-v+mod)%mod);
            }
        }
    }
    if(inv&&op==XOR){
        for(int i=0;i<sz;i++){
            a[i]/=sz;  // may be mod inv?  (NOTE modInv never going to be wrong so...)
        }
    }
}
