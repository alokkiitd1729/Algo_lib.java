// https://www.hackerrank.com/contests/goc-cdc-series-4/challenges/just-another-noob/problem


import java.util.*;
import java.io.*;
public class CSES{
// taking inputs
static BufferedReader s1;
static BufferedWriter out;
static String read() throws IOException{String line="";while(line.length()==0){line=s1.readLine();continue;}return line;}
static int int_v (String s1){return Integer.parseInt(s1);}
static long long_v(String s1){return Long.parseLong(s1);}
static int[] int_arr() throws IOException{String[] a=read().split(" ");int[] b=new int[a.length];for(int i=0;i<a.length;i++){b[i]=int_v(a[i]);}return b;}
static long[] long_arr() throws IOException{String[] a=read().split(" ");long[] b=new long[a.length];for(int i=0;i<a.length;i++){b[i]=long_v(a[i]);}return b;}
static void sort(int[] a){List<Integer> l=new ArrayList<>();for(int z:a){l.add(z);}Collections.sort(l);for(int i=0;i<a.length;i++){a[i]=l.get(i);}}
static void assign(){s1=new BufferedReader(new InputStreamReader(System.in));out=new BufferedWriter(new OutputStreamWriter(System.out));}
//......................................@uthor_Alx..............................................
static int BIT[];
static void update(int x, int delta){
       while(x<BIT.length){
            BIT[x] += delta;
           x+=x&-x;
       }
}
static int query(int x){
    int sum = 0;
        while(x>0){
            sum += BIT[x];
            x-=x&-x;
        }
     return sum;
} 
static int find( int k,int n){.   // finds the least index j such that there are k many 1(s) BIT[1...j]
    int l=1,r=n,ans=-1;
    while(l<=r){
        int m=(l+r)/2;
        int f=query(m);
        if(f>=k){
            r=m-1;
            ans=m;
        }
        else if(f<k){
            l=m+1;
        }
    }
    return ans;
}
 
public static void main(String[] args) throws  IOException{
                        assign();
                          int n=int_v(read());
                          int[] arr=int_arr();
                          BIT=new int[n+2];
                          for(int i=1;i<=n;i++)update(i,1);
                          int[] res=new int[n+1];
                          for(int i=n-1;i>=0;i--){
                              int tmp=find(arr[i],n);
                              res[tmp]=i+1;
                              update(tmp,-1);
                          }
                          for(int i=1;i<=n;i++)out.write(res[i]+" ");
                          out.flush();
    }
}
