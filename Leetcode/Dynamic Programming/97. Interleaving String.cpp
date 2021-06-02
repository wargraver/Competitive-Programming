int dp[105][105][2];
class Solution {
public:
    int check(string s1,string s2,int i,int j){
        if(i==s1.size() && j==s2.size()) return 1;
         while(i<s1.size() && j<s2.size()){
             if(i==s1.size()-1 && j==s2.size()-1 && s1[i]==s2[j]) return 1;
             else if(s1[i]==s2[j]){
                 i++;j++;
             }
             else return 0;
         }
        return 0;
    }
    bool ways(string s1,string s2,string s3,int i1,int i2,int flag,int i3){
        // cout<<i1<<" "<<i2<<" "<<i3<<endl;
         if(dp[i1][i2][flag]==-1){
             if(i3==s3.size()) return dp[i1][i2][flag]=1;
             else if(i1==s1.size() && i2==s2.size()) return dp[i1][i2][flag]=1;
             else if(i1==s1.size()) return dp[i1][i2][flag]=check(s2,s3,i2,i3);
             else if(i2==s2.size()) return dp[i1][i2][flag]=check(s1,s3,i1,i3);
             else if(flag==0){
                 if(s1[i1]!=s3[i3]) return dp[i1][i2][flag]=0;
                 else return dp[i1][i2][flag] =ways(s1,s2,s3,i1+1,i2,0,i3+1) + ways(s1,s2,s3,i1+1,i2,1,i3+1);
             }
             else{
                 if(s2[i2]!=s3[i3]) return dp[i1][i2][flag]=0;
                 else return dp[i1][i2][flag]=ways(s1,s2,s3,i1,i2+1,1,i3+1) + ways(s1,s2,s3,i1,i2+1,0,i3+1);
             }
         }
        else return dp[i1][i2][flag];
    }
    bool isInterleave(string s1, string s2, string s3) {
         int i,j,k,n,m,ct=0;
         n = s1.size();
         m = s2.size();
         ct = s3.size();
         for(i=0;i<=n+2;i++){
             for(j=0;j<=m+2;j++){
                 dp[i][j][0]=-1;
                 dp[i][j][1]=-1;
             }
         }
       //  cout<<s1.size()<<" "<<s2.size()<<" "<<s3.size()<<endl;
         if(s1.size()+s2.size()!=s3.size()) return false; 
         int m1 = ways(s1,s2,s3,0,0,0,0);
         for(i=0;i<=m+2;i++){
             for(j=0;j<=n+2;j++){
                 dp[i][j][0]=-1;
                 dp[i][j][1]=-1;
             }
         }
         int m2 =  ways(s2,s1,s3,0,0,0,0);
        // cout<<m1<<" "<<m2<<endl;
         return m1 or m2;
    }
};
