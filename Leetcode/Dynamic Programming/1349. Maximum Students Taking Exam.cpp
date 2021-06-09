int dp[9][9][257][257];
int bit;
class Solution {
public:
    int ways(vector<vector<char>> seats,int n,int m,int i,int j,int prev_bit,int curr_bit){
        if(i>=n) return 0;
        if(j>=m) return ways(seats,n,m,i+1,0,curr_bit,bit);
        else if(dp[i][j][prev_bit][curr_bit]==-1){
            int val = curr_bit;
            if(seats[i][j]=='.'){
                   int flag=0;
                   if(j-1>=0){
                       if((prev_bit & 1<<(j-1))!=pow(2,j-1)) flag=1; 
                   }
                   if(j+1<=m-1){
                       if((prev_bit & 1<<(j+1))!=pow(2,j+1)) flag=1;
                   }
                   if(flag==0){
                    return dp[i][j][prev_bit][curr_bit]=max(1+ways(seats,n,m,i,j+2,prev_bit,curr_bit xor 1<<j),ways(seats,n,m,i,j+1,prev_bit,curr_bit));
                 }
                 else return dp[i][j][prev_bit][curr_bit]=ways(seats,n,m,i,j+1,prev_bit,curr_bit);
            }
            else return dp[i][j][prev_bit][curr_bit]=ways(seats,n,m,i,j+1,prev_bit,curr_bit);
        }
        //return 0;
        else return dp[i][j][prev_bit][curr_bit];
    }
    int maxStudents(vector<vector<char>>& seats) {
        int i,j,k,n,m,ct=0;
        n=seats.size();m=seats[0].size();
        bit = pow(2,m)-1;
       memset(dp,-1,sizeof(dp));
        //bit stores at which coloum a student is sitting in the previous row
        //if the bit is set means there is no one sitting on that location
        return ways(seats,n,m,0,0,bit,bit);
    }
};
