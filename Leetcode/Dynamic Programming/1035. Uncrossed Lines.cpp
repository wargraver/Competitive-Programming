class Solution {
public:
    int dp[505][505];
    int ways(vector<int> A,vector<int> B,int st1,int st2){
        if(st1>=A.size()) return 0;
        else if(st2>=B.size()) return 0;
        else if(dp[st1][st2]==-1){
            if(A[st1]==B[st2]) return dp[st1][st2]=1+ways(A,B,st1+1,st2+1);
            else return dp[st1][st2]=max(ways(A,B,st1+1,st2),ways(A,B,st1,st2+1));
        }
        else return dp[st1][st2];
    }
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int i,j,k,n1=A.size(),n2=B.size(),ans=0;
        memset(dp,-1,sizeof(dp));
        return ways(A,B,0,0);
    }
};
