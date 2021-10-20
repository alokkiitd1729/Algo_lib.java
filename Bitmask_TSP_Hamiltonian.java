// https://www.hackerrank.com/contests/goc-cdc-series-6/challenges/visit-them-all/submissions/code/1335864138

import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        int n=s.nextInt(),m=s.nextInt();
        int[][] g=new int[n][n];
        for(int i=0;i<n;i++){
            Arrays.fill(g[i],200000000);
            g[i][i]=0;
        }
        for(int i=0;i<m;i++){
            int a=s.nextInt()-1,b=s.nextInt()-1,w=s.nextInt();
            g[a][b]=g[b][a]=w;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    g[i][j]=Math.min(g[i][j],g[i][k]+g[k][j]);
                }
            }
        }
        int[][] dp=new int[n][1<<n];// dp[i][mask]=min time to start from 1 and travel all set_bit index and end at i
        for(int i=0;i<n;i++)Arrays.fill(dp[i],200000000);
        for(int i=0;i<n;i++)dp[i][1<<i]=g[0][i];
        for(int mask=1;mask<1<<n;mask++){
            for(int i=0;i<n;i++){
                if((mask&1<<i)==0) continue;
                int tmask=mask^(1<<i);
                for(int j=0;j<n;j++){
                    if((tmask&1<<j)!=0){
                        dp[i][mask]=Math.min(dp[i][mask],dp[j][tmask]+g[i][j]);
                    }
                }
            }
        }
        System.out.print(dp[n-1][(1<<n)-1]+"");
    }
}
