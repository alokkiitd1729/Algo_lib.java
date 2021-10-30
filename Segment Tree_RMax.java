import java.util.*;
import java.io.*;
//import java.math.*;
//https://www.hackerrank.com/goc-cdc-series-1
  class Task{
//  ..............code begins here..............

static long mod=(long)1e9+7,mod1=998244353l,inf=(long)1e18+5;
static int[] st;
static void build(int n,int b,int e,int[] p){
    if(b==e){
        st[n]= p[b];
        return;
    }
    int cl=2*n,cr=2*n+1,m=(b+e)/2;
    build(cl,b,m,p);
    build(cr,m+1,e,p);
    st[n]=Math.max(st[cl],st[cr]);
}
static void upd(int n,int b,int e,int i,int x){    //point upd.  0 based indexing a[i]=x
    if(b==e){
      t[n]=x; return;
    }
    int cl=2*n,cr=2*n+1,m=(b+e)/2;
    if(i<=m) upd(cl,b,m,i,x);
    else upd(cr,m+1,e,i,x);
    t[n]=Math.max(t[cl],t[cr]);
 }
static int qry(int n,int b,int e,int i,int j){  //range max.  (1,0,n-1,i,j).  0 based indexing of i,j
    if(b==i&&e==j) return st[n];
    int cl=2*n,cr=2*n+1,m=(b+e)/2;
    if(j<=m)return qry(cl,b,m,i,j);
    else if(i>m) return qry(cr,m+1,e,i,j);
    else{
        int L=qry(cl,b,m,i,m),R=qry(cr,m+1,e,m+1,j);
        return Math.max(L,R);
    }
}


static void solve() throws  IOException{
    int n=int_v(read());
    int[] a=int_arr();
    st=new int[4*n];
    Arrays.fill(st,-2000000000);
    build(1,0,n-1,a);
    int q=int_v(read());
    while(q--!=0){
        int[] b=int_arr();
        out.write(qry(1,0,n-1,b[0],b[1])+"\n");
    }
}

public static void main(String[] args) throws  IOException{
    assign();
    int t=1;//int_v(read()),cn=1;
    while(t--!=0){
        //out.write("Case #"+cn+": ");
        solve();
        //cn++;
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
static int add(int a,int b){int z=a+b;if(z>=mod)z-=mod;return z;}
static long gcd(long a,long b){if(b==0){return a;}return gcd(b,a%b);}
static long Modpow(long a,long p,long m){long res=1;while(p>0){if((p&1)!=0){res=(res*a)%m;}p >>=1;a=(a*a)%m;}return res%m;}
static long Modmul(long a,long b,long m){return ((a%m)*(b%m))%m;}
static long ModInv(long a,long m){return Modpow(a,m-2,m);}
//static long nck(int n,int r,long m){if(r>n){return 0l;}return Modmul(f[n],ModInv(Modmul(f[n-r],f[r],m),m),m);}
//static long[] f;
}
