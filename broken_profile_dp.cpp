int board[m+1][n+1], dp[m+1][(1<<n)];
int n,m;

bool occupied(int i, int q){ //Check if ith block is occupied in profile q.
    return q&(1 << (i-1));
}

void search(int i, int j, int p, int q){
    if(i == n+1){
        dp[j+1][p] += dp[j][q];
        return;
    }
    if(occupied(i, q)){
        search(i+1, j, p, q);
        return;
    }
    if(i+1 <= n && !occupied(i+1, q)){
        search(i+2, j, p, q);
    }
    if(j+1 <= m){
        search(i+1, j, p^(1 << (i-1)), q);
    }
}

int main(){
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1; //Initial condition
    for(int j = 1; j < m; j++){
        for(int q = 0; q < (1<<n); q++){
            search(1, j, 0, q);
        }
    }
    cout<<dp[m][0]<<endl;
}
