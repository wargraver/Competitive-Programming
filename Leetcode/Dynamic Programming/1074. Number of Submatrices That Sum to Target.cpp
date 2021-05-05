class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int i,j,k,n,m,ct=0;
        n=matrix.size();
        m=matrix[0].size();
        int dp[n+5][m+5];
        //Stroing prefix sum of coloum j of row i in dp[i][j]
        for(i=0;i<n;i++){
            int sum=0;
            for(j=0;j<m;j++){
                dp[i][j]=sum+matrix[i][j];
                sum = dp[i][j];
            }
        }
        int ans=0;
        //Iterating through every possible commbination of coloumns
        for(int c1=0;c1<m;c1++){
            for(int c2=c1;c2<m;c2++){
               map<int,int> dict;
               vector<int> vect;
               int pref=0;
                //calculating number of subarray sum equals target
               vect.push_back(0);
               for(i=0;i<n;i++){
                   int sum = dp[i][c2]-dp[i][c1]+matrix[i][c1];
                   vect.push_back(pref+sum); 
                   pref+=sum;
               }
               for(i=0;i<vect.size();i++){
                   k = vect[i]-target;
                   if(dict.find(k)!=dict.end()){
                   j=dict[k];
                   ans+=j;
                   }
                   dict[vect[i]]++;
               }
                
            }
        }
        return ans;
    }
};
