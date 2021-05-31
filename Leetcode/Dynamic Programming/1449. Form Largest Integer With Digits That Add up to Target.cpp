int dp[5005][5005];
class Solution {
public:
    int ways(int i,vector<int> cost,int target){
        if(i+1 == cost.size() && target==0) return dp[i][target]=0;
        else if(target==0) return dp[i][target]=0;
        else if(i+1==cost.size()) return dp[i][target]=-1e9;
        else if(dp[i][target]==-1){
            if(target-cost[i]>=0){
                int m1 = 1+ways(i,cost,target-cost[i]);
                int m2 = ways(i+1,cost,target)
           // return dp[i][target]=max(1+ways(i,cost,target-cost[i]),ways(i+1,cost,target));
               if(m1==m2){
                   if(cost[i])
               }
            else return dp[i][target] = max(m1,m2); 
            }
            else return dp[i][target]=ways(i+1,cost,target);
        }
        else return dp[i][target];
    }
    string largestNumber(vector<int>& cost, int target) {
        int i,j,k,n,m,ct=0;
        int sum = target;
        n = cost.size();
        for(i=0;i<=n+2;i++){
            for(j=0;j<=target+1;j++) dp[i][j]=-1;
        }
        int m1 = ways(0,cost,target);
        if(m1<0) m1=0;
       // cout<<m1<<endl;
         string str = "";
        k = target;
        map<int,string> dict;
        for(i=1;i<=9;i++){
            dict[cost[i-1]] = to_string(i);
        }
        for(i=0;i<n;i++){
            m = dp[i][k];
           // cout<<i<<" "<<k<<" "<<dp[i][k]<<endl;
            while(k>=0 && k-cost[i]>=0 && dp[i][k-cost[i]]>=0 && dp[i][k]==dp[i][k-cost[i]]+1){
                auto it = dict.find(cost[i]);
                str+= it->second;
               // cout<<i+1<<endl;
                k = k-cost[i];
            }
        }
        sort(str.begin(),str.end());
        reverse(str.begin(),str.end());
        if(str.size()==0) str+='0';
        return str;
    }
};
