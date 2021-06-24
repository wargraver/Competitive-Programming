//Creating a set of key(distance,index) for looking up minimum distance in logn time
set<pair<int,int>> pq;
//Global Matrix for storing weight of each edge
int wt[105][105];

class Solution {
public:
    void djkstrA(int i,int dp[],int n,vector<int> adj[]){
        if(pq.size()==0) return;
        else{
            auto kt = pq.begin();
            int dist = kt->first;
            int ind = kt->second;
            pq.erase(kt);
            for(auto x:adj[ind]){
                if(dp[x]>dp[ind]+wt[ind][x]){
                    auto it = pq.find({dp[x],x});
                    pq.erase(it);
                    dp[x] = dp[ind]+wt[ind][x];
                    pq.insert({dp[x],x});
                }
            }
            djkstrA(i,dp,n,adj);
        }
    }
    int findTheCity(int n, vector<vector<int>>& edges, int d) {
        int i,j,k,m,ct=0,val,ans=1e9;
        vector<int> adj[n];
        for(i=0;i<edges.size();i++){
            j = edges[i][0];
            k = edges[i][1];
            wt[k][j] = edges[i][2];
            wt[j][k] = edges[i][2];
            adj[j].push_back(k);
            adj[k].push_back(j);
        }
        //Checking for every node and using DjkstrA for each and every node as source
        for(i=0;i<n;i++){
            int dp[n];
            pq.clear();
            for(j=0;j<n;j++) dp[j]=1e9;
            dp[i]=0;
            for(j=0;j<n;j++) pq.insert({dp[j],j});
            djkstrA(i,dp,n,adj);
            int k=0;
            for(j=0;j<n;j++){
                if(dp[j]<=d) k++;
            }
            if(ans>=k){
                ans=k;
                val=i;
            }
        }
        return val;
    }
};
