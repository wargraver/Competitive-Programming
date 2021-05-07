int dp[505][505];
class Solution {
public:
    int ways(int i,int j,string s1,string s2){
        if(i>=s1.size() || j>=s2.size()) return 0;
        else if(dp[i][j]==-1){
            if(s1[i]==s2[j]) return dp[i][j]=ways(i+1,j+1,s1,s2)+1;
            return dp[i][j]=max(ways(i+1,j,s1,s2),ways(i,j+1,s1,s2));
        }
        else return dp[i][j];
    }
    int minDistance(string word1, string word2) {
         int i,j,k,n,m,ct=0;
         int n1,n2;
         n1 = word1.size();
         n2 = word2.size();
         for(i=0;i<=n1;i++){
             for(j=0;j<=n2;j++) dp[i][j]=-1;
         }
         k = ways(0,0,word1,word2);
        return (n1+n2-2*k);
    }
};
