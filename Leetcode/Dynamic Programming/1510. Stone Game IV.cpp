int dp[100005];
bool player1(int n){
    if(n<=0) return false;
    else if(dp[n]==-1){
        for(int j=1;j*j<=n;j++){
            if(player1(n-j*j)==false) {dp[n]=1;return true;}
        }
        dp[n]=0;
        return false;
    }
    else if(dp[n]==0) return false;
    else return true;
}
class Solution {
public:
    bool winnerSquareGame(int n) {
        int i,j,k,m,ct=0;
        for(i=0;i<=n+2;i++) dp[i]=-1;
        if(n==1) return true;
        return player1(n);
    }
};
