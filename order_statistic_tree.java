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

// find kth largest/smallest element in a given multiset -  for high value do co-ordinate compressing     
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
 	        		  	int[] n1=int_arr();
 	        		  	int n=n1[0],k=n1[1];
 	        		  	int[] arr=int_arr();
 	        		  	int[] c=arr.clone();
 	        		  	sort(c);
 	        		  	int j=1,k1=k;k=k/2+k%2;
 	        		  	Map<Integer,List<Integer>> map=new HashMap<>();
 	        		  	Map<Integer,Integer> ctr=new HashMap<>();
 	        		  	int[] map1=new int[n+2];
 	        		  	for(int x:c){
 	        		  		map1[j]=x;
 	        		  		ctr.put(x,0);
 	        		  		map.computeIfAbsent(x,key ->new ArrayList<>()).add(j);
 	        		  		j++;
 	        		  	}
 	        		  	int[] BIT=new int[n+2];
 	        		  	for(int i=0;i<n;i++){
 	        		  		int xx=ctr.get(arr[i]),mapped=map.get(arr[i]).get(xx);
 	        		  		ctr.put(arr[i],xx+1);
 	        		  		arr[i]=mapped;
 	        		  	}
 	        		  	for(int i=1;i<=k1;i++){
 	        		  		update(arr[i-1],1,BIT);
 	        		  	}
 	        		  	out.write(map1[find(BIT,k,n)]+" ");j=0;
 	        		  	for(int i=k1;i<n;i++){
 	        		  		update(arr[i],1,BIT);
 	        		  		update(arr[j],-1,BIT);
 	        		  		out.write(map1[find(BIT,k,n)]+" ");j++;
 	        		  	}
                         out.flush();
 	}
 }
