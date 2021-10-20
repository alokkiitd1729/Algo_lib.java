/*
      https://www.facebook.com/codingcompetitions/hacker-cup/2021/round-2/problems/B
      https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/xor-tree-4-c6f207f4/editorial/
      https://www.codechef.com/viewsolution/51520214
      
      calculate any function  - f(path,u,v)..... where path is shortest path between (u,v)
*/

import java.util.*;
import java.io.*;
//import java.math.*;

class chef{
        //  ..............code begins here..............
static long mod=(long)1e9+7;
static List<int[]>[] g;
static int[][] f;
static long[][] dp;
static int[] dep;
static void dfs(int u, int p,int h,long w){
	  f[u][0]=p;dep[u]=h;
	  dp[u][0]=w;
	  for(int i=1;i<=17;i++){
	    f[u][i]= f[f[u][i-1]][i-1];
	    dp[u][i]=dp[f[u][i-1]][i-1]+dp[u][i-1];
	  }

	  for(int[] v: g[u]){
	    if(v[0]!=p) dfs(v[0],u,h+1,v[1]);
	  }
}
static long ok(int u, int v){ // find sum of weight of edges in shortest path b/w (u,v)....   can be used to find any function f(u,v)=Or,Xor,And
	long res=0;
    if(dep[u]>dep[v]){
        int tmp=v;
        v=u;u=tmp;
    }
    int diff=dep[v]-dep[u];
    for(int i=17;i>=0;i--){
        if((diff&1<<i)!=0){
        	res+=dp[v][i];
            v=f[v][i];
        }
    }
    for(int i=17;i>=0;i--){
        if(f[u][i]!=f[v][i]){
            res+=dp[u][i]+dp[v][i];
            u=f[u][i];v=f[v][i];
        }
    }
    //lca=u;
    if(u!=v){
        res+=dp[u][0]+dp[v][0];
	// lca=parent(u)=parent(v)
    }
    return res;
}
static void solve() throws  IOException {
        int[] x=int_arr();
        int n=x[0],q=x[1],r=x[2];
        g=new ArrayList[n+1];
        dp=new long[n+1][18];
        f=new int[n+1][18]; dep=new int[n+1];
        for(int i=0;i<=n;i++)g[i]=new ArrayList<>();
        for(int i=1;i<n;i++){
        	int[] e=int_arr();
        	g[e[0]].add(new int[]{e[1],e[2]});
        	g[e[1]].add(new int[]{e[0],e[2]});
        }
        dfs(r,r,0,0);
        for(int i=0;i<q;i++){
        	int[] e=int_arr();
        	out.write(ok(e[0],e[1])+"\n");
        }
}
   
public static void main(String[] args) throws  IOException{
                assign();
                int t=int_v(read()),cn=1;
                while(t--!=0){
                    solve();
                }
                out.flush();
}

// taking inputs

static BufferedReader s1;
static BufferedWriter out;
static String read() throws IOException{String line="";while(line.length()==0){line=s1.readLine();continue;}return line;}
static int int_v (String s1){return Integer.parseInt(s1);}
static long long_v(String s1){return Long.parseLong(s1);}
static void sort(int[] a){List<Integer> l=new ArrayList<>();for(int x:a){l.add(x);}Collections.sort(l);for(int i=0;i<a.length;i++){a[i]=l.get(i);}}
static int[] int_arr() throws IOException{String[] a=read().split(" ");int[] b=new int[a.length];for(int i=0;i<a.length;i++){b[i]=int_v(a[i]);}return b;}
static long[] long_arr() throws IOException{String[] a=read().split(" ");long[] b=new long[a.length];for(int i=0;i<a.length;i++){b[i]=long_v(a[i]);}return b;}
static void assign(){s1=new BufferedReader(new InputStreamReader(System.in));out=new BufferedWriter(new OutputStreamWriter(System.out));}
//static String setpreciosion(double d,int k){BigDecimal d1 = new BigDecimal(Double.toString(d));return d1.setScale(k,RoundingMode.HALF_UP).toString();}//UP DOWN HALF_UP
static int gcd(int a,int b){if(b==0){return a;}return gcd(b,a%b);}
static long Modpow(long a,long p,long m){long res=1;while(p>0){if((p&1)!=0){res=(res*a)%m;}p >>=1;a=(a*a)%m;}return res%m;}
static long Modmul(long a,long b,long m){return ((a%m)*(b%m))%m;}
static long ModInv(long a,long m){return Modpow(a,m-2,m);}
//static long nck(int n,int r,long m){if(r>n){return 0l;}return Modmul(f[n],ModInv(Modmul(f[n-r],f[r],m),m),m);}
//static long[] f;
}
