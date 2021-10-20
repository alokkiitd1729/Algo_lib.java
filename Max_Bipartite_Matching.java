//https://csacademy.com/contest/archive/task/no-prime-sum/statement/
//Minimum Vertex cover = Max Matching - Bipartite Graph
// Kuhn's Algo complexity - O(VE)
//https://github.com/alokkiitd1729/Algo_lib.java/blob/main/Minimum_vertex_cover_bipartite.cpp
import java.util.*;
import java.lang.*;
import java.io.*;

// Please name your class Main
class Main {
    static boolean[] p=new boolean[200001];
    static List<Integer>[] g=new ArrayList[2000];
    static int f=1;
    static int[] vis=new int[2000],mx,my;    // match x, match y
    static void sieve(){
        p[0]=p[1]=true;
        for(int i=2;i<=500;i++){
            if(p[i]) continue;
            for(int j=2*i;j<=200000;j+=i){
                p[j]=true;
            }
        }
    }
    static boolean dfs(int u){
        if(vis[u]==f) return false;
        vis[u]=f;
        for(int v:g[u]){
            if(mx[v]==-1||dfs(mx[v])){
                mx[v]=u;
                my[u]=v;
                return true;
            }
        }
        return false;
    }
	public static void main (String[] args) throws java.lang.Exception {
	    Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		List<Integer> o=new ArrayList<>(),e=new ArrayList<>();
		for(int i=0;i<n;i++){
		    int a=s.nextInt();
		    if(a%2==0)e.add(a);
		    else o.add(a);
		}
		sieve();
		for(int i=0;i<2000;i++)g[i]=new ArrayList<>();
		for(int i=0;i<o.size();i++){
		    for(int j=0;j<e.size();j++){
		        if(!p[(int)o.get(i)+(int)e.get(j)]){
		            g[i].add(j);
		            g[j].add(i);
		        }
		    }
		}
		mx=new int[(int)e.size()];
		my=new int[(int)o.size()];
		Arrays.fill(mx,-1);
		Arrays.fill(my,-1);
		int max_match=0;
		for(int i=0;i<o.size();i++){
		    if(my[i]==-1){
		        if(dfs(i))max_match++;
		        f++;
		    }
		}
	    System.out.print(max_match+"");
	}
}
