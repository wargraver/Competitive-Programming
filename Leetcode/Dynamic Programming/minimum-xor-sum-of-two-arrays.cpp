int dp[16][16390];
class Solution {
public:
    int ways(vector<int> nums1,vector<int> nums2,int m,int i){
        if(i==nums1.size() && m==0) return 0;
        else if(i==nums1.size() && m!=0) return 1e9;
        if(m==0) return 0;
        else if(dp[i][m]==-1){
            int ans = 1e9;
            for(int j=0;j<nums2.size();j++){
                int new_bit = m;
                if((new_bit & 1<<j)==pow(2,j)){
                    new_bit = (m xor 1<<j);
                    ans = min(ans,(nums1[i] xor nums2[j]) + ways(nums1,nums2,new_bit,i+1));
               }  
            }
            return dp[i][m]=ans;
        }
        else return dp[i][m];
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int i,j,k,n,m,ct=0;
        n = nums1.size();
        m = pow(2,n)-1;
         for(i=0;i<=n;i++){
            for(j=0;j<=m+2;j++) dp[i][j]=-1;
        }
        return ways(nums1,nums2,m,0);
    }
};
