int dp[205][205];
class Solution {
public:
    int ways(vector<vector<int>> vect,int i,int j){
        if(i==vect.size()-1 && j==vect[0].size()-1){
            if(vect[i][j]>=0) return 0;
            else return vect[i][j];
        }
        else if(dp[i][j]==-1){
       if(i==vect.size()-1){
            int k = ways(vect,i,j+1)+vect[i][j];
            if(k<0) return dp[i][j]=k;
            else return dp[i][j]=0;
        }
        else if(j==vect[0].size()-1){
            int k = ways(vect,i+1,j) + vect[i][j];
            if(k<0) return dp[i][j]=k;
            else return dp[i][j]=0;
        }
        else{
            int k1 = ways(vect,i+1,j)+vect[i][j];
            int k2 = ways(vect,i,j+1)+vect[i][j];
            if(k1>=0) k1=0;
            if(k2>=0) k2=0;
            return dp[i][j]=max(k1,k2);
        }
        }
        else return dp[i][j];
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int i,j,k,n=dungeon.size(),m=dungeon[0].size(),ct=0;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++) dp[i][j]=-1;
        }
        int it = ways(dungeon,0,0);
        return abs(it)+1;
    }
};
