import java.util.*;
import java.io.*;
public class TestClass{

static int[] parent;
static int[] rank;
// dsu disjoint set union
 static void make_set(int x){
 	parent[x]=x;
 	rank[x]=0;
 }
 static int find_set(int x){
 	if(parent[x]==x){return x;}
 	return parent[x]=find_set(parent[x]);
 }
 static void union_set(int x, int y){
 	x=find_set(x);
 	y=find_set(y);
 	if(x==y){rank[x]++;}
 	else if(rank[x]<rank[y]){int k=x;x=y;y=k;}
 	parent[y]=x;
 }


public static void main(String[] args) throws FileNotFoundException, IOException{
       Scanner s=new Scanner(System.in);
       BufferedWriter out=new BufferedWriter(new OutputStreamWriter(System.out));
       	int n=s.nextInt(),m=s.nextInt();
       	parent=new int[n+1];
       	rank=new int[n+1];
       	int[][] edge=new int[m][3];
       	for(int i=0;i<m;i++){
       	    edge[i][0]=s.nextInt();edge[i][1]=s.nextInt();edge[i][2]=s.nextInt();
       	}
       	Arrays.sort(edge,new Comparator<int[]>(){
       	    public int compare(int[] a, int[] b){
       	        return a[2]-b[2];
       	    }
       	});
       	int res=0;
       	for(int i=1;i<=n;i++){make_set(i);}
       	for(int i=0;i<m;i++){
       	    if(find_set(edge[i][0])!=find_set(edge[i][1])){
       	        res+=edge[i][2];
       	        union_set(edge[i][0],edge[i][1]);
       	    }
       	}
       out.write(res+"");
          out.flush();
       	}
       }
        
  
 
