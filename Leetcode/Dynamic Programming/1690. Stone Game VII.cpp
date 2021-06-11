int store[1005][1005],dp[1005][1005];
class Solution {
public:
    int ways(int st,int en,int flag){
        if(st>en) return 0;
        if(st==en) return 0;
        else if(dp[st][en]==-1){
            //Stimulating ALice turns
           // cout<<flag<<" "<<st<<" "<<en<<" "<<store[st][en-1]<<" "<<store[st+1][en]<<endl;
            if(flag==0){
                 return dp[st][en]=max(store[st][en-1]-ways(st,en-1,1),store[st+1][en]-ways(st+1,en,1));
            }
            //Stimulating BOB's turn
            else{
                return dp[st][en]=max(store[st][en-1]-ways(st,en-1,0),store[st+1][en]-ways(st+1,en,0));
            }
        }
        else return dp[st][en];
    }
    int stoneGameVII(vector<int>& stones) {
        int i,j,k,n=stones.size();
        for(i=0;i<n;i++){
            int sum=0;
            for(j=i;j<n;j++) {
                sum+=stones[j];
                store[i][j] = sum;
                dp[i][j]=-1;
            }
        }
        return ways(0,n-1,0);
    }
};
