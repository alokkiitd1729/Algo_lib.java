/*
    No Prime Sum
    https://csacademy.com/contest/archive/task/no-prime-sum/solution/
    
    Kuhn's Algo O(VE)

*/


#include<bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll,ll> pll;
#define ff first
#define ss second
#define pb emplace_back
#define AI(x) begin(x),end(x)
template<class I>bool chmax(I&a,I b){return a<b?(a=b,true):false;}
template<class I>bool chmin(I&a,I b){return b<a?(a=b,true):false;} 
#ifdef OWO
#define debug(args...) SDF(#args, args)
#define OIU(args...) ostream& operator<<(ostream&O,args)
#define LKJ(S,B,E,F) template<class...T>OIU(S<T...>s){O<<B;int c=0;for(auto i:s)O<<(c++?", ":"")<<F;return O<<E;}
LKJ(vector,'[',']',i)LKJ(deque,'[',']',i)LKJ(set,'{','}',i)LKJ(multiset,'{','}',i)LKJ(unordered_set,'{','}',i)LKJ(map,'{','}',i.ff<<':'<<i.ss)LKJ(unordered_map,'{','}',i.ff<<':'<<i.ss)
template<class...T>void SDF(const char* s,T...a){int c=sizeof...(T);if(!c){cerr<<"\033[1;32mvoid\033[0m\n";return;}(cerr<<"\033[1;32m("<<s<<") = (",...,(cerr<<a<<(--c?", ":")\033[0m\n")));}
template<class T,size_t N>OIU(array<T,N>a){return O<<vector<T>(AI(a));}template<class...T>OIU(pair<T...>p){return O<<'('<<p.ff<<','<<p.ss<<')';}template<class...T>OIU(tuple<T...>t){return O<<'(',apply([&O](T...s){int c=0;(...,(O<<(c++?", ":"")<<s));},t),O<<')';}
#else
#pragma GCC optimize("Ofast")
#define debug(...) ((void)0)
#endif

const int kN = 2002;
const int kC = 200002;

int n;
vector<int> adj[kN];
int mx[kN], my[kN];
int vis[kN], tot = 0;
int np[kC];
int sx[kN], sy[kN];

bool dfs(int u){
	if(vis[u] == tot) return false;
	vis[u] = tot;
	for(int v: adj[u]){
		if(my[v] == -1 or dfs(my[v])){
			mx[u] = v;
			my[v] = u;
			return true;
		}
	}
	return false;
}

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	np[0] = np[1] = true;
	for(int i = 2; i < kC; ++i){
		if(np[i]) continue;
		for(int j = i + i; j < kC; j += i)
			np[j] = true;
	}

//######################################################### Making Graph. ###########################################################
	cin >> n;
	vector<int> x, y;
	for(int i = 0, v; i < n; ++i){
		cin >> v;
		(v & 1 ? x : y).pb(v);
	}

	if(x.size() > y.size()) swap(x, y);
	int nx = x.size(), ny = y.size();
	for(int i = 0; i < nx; ++i)
		for(int j = 0; j < ny; ++j)
			if(!np[x[i] + y[j]]) adj[i].pb(j);

	for(int i = 0; i < nx; ++i) mx[i] = -1;    // mx[i]=1 => i from left(X) has been matched with some j form right(Y)
	for(int i = 0; i < ny; ++i) my[i] = -1;    // my[j]=1 => j from right(Y) has been matched with some i form left(X)

	int mvc = 0;      // Minimum Vertex Covering == Maximum Bipartite Matching


//############################################# Before calling dfs we can find some random Match to make it fast ###########################################################
	for(int i = 0; i < nx; ++i)
		if(mx[i] == -1){
		    tot++;
		    mvc += dfs(i);
		}
	cout << mvc << '\n';          // min vertex cover



//######################################################### In order to know the actual vertices of MVC ###########################################################
	vector<int> stk;
	for(int i = 0; i < nx; ++i)
		if(mx[i] != -1) sx[i] = true;         // i has been matched
		else stk.pb(i);                       // i has NOT been matched

	while(!stk.empty()){
		int u = stk.back(); stk.pop_back();
		for(int v: adj[u]){
			if(!sy[v]){
				sy[v] = true;
				if(sx[my[v]]){
					sx[my[v]] = false;
					stk.pb(my[v]);
				}
			}
		}
	}

	for(int i = 0; i < nx; ++i) if(sx[i]) cout << x[i] << ' ';
	for(int i = 0; i < ny; ++i) if(sy[i]) cout << y[i] << ' ';

	return 0;
}
