int n1,n2;
int dp[505][505];
int ways(int st1,int st2,string w1,string w2){
    if(st2==n2) return n1-st1;
    else if(st1==n1){
        return n2-st2;
    }
    else if(dp[st1][st2]==-1){
        if(w1[st1]==w2[st2]) return dp[st1][st2]=ways(st1+1,st2+1,w1,w2);
        else return dp[st1][st2]=min(1+ways(st1,st2+1,w1,w2),min(1+ways(st1+1,st2,w1,w2),1+ways(st1+1,st2+1,w1,w2)));
    }
    else return dp[st1][st2];
}
class Solution {
public:
    int minDistance(string word1, string word2) {
        n1=word1.size();
        n2=word2.size();
        for(int i=0;i<=n1;i++){
            for(int j=0;j<=n2;j++) dp[i][j]=-1;
        }
        if(n1==0) return n2;
        return ways(0,0,word1,word2);
    }
};
