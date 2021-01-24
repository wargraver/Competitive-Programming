class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int i,j,n,m;
         n=matrix.size();m=matrix[0].size();
        int dp[n+5][m+5];
        int val=0;multiset<int> dict;
        for(i=0;i<n;i++){
            val=0;
            for(j=0;j<m;j++){
                dp[i][j]=val xor matrix[i][j];
                val=dp[i][j];
            }
        }
       /* for(i=0;i<n;i++){
            for(j=0;j<m;j++) cout<<dp[i][j]<<" ";
            cout<<endl;
        }*/
        
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(i==0){val=dp[i][j];
                dict.insert(val);
                if(dict.size()>k) {
                    auto it=dict.begin();
                    dict.erase(it);
                }}
                if(i!=0){
                    val=dp[i-1][j] xor dp[i][j];
                    dp[i][j]=val;
                    dict.insert(val);
                if(dict.size()>k) {
                    auto it=dict.begin();
                    dict.erase(it);
                }
                } 
            }
        }
        //for(auto it=dict.begin();it!=dict.end();it++) cout<<*it<<" ";
       // cout<<endl;
        auto it=dict.begin();
        val=*it;
        return val;
    }
};
