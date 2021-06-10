typedef long long int ll;
ll dp[31][31];
class Solution {
public:
   ll fill(ll n, ll k)
   {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    if(dp[n][k]==-1) return dp[n][k]=fill(n - 1, k - 1) + fill(n - 1, k);
    else return dp[n][k];
    }
    string word(ll h,ll v,ll k,string ans,ll flag){
           if(h==0 && v==0) return ans;
            else if(flag==0){
            if(h==0) return word(h,v,k,ans,1);
            ll ans1 = fill(h+v-1,h-1);
            if(ans1>=k){
                ans+='H';
                h--;
                return word(h,v,k,ans,0);
            }
            else return word(h,v,k-ans1,ans,1);
           }
         else{
           if(v==0) return word(h,v,k,ans,0);
            ll ans1 = fill(h+v-1,v-1);
            if(ans1>=k){
                ans+='V';
                v--;
                return word(h,v,k,ans,0);
            }
            else return word(h,v,k-ans1,ans,0);
        }
        
    }
    string kthSmallestPath(vector<int>& destination, int k) {
        ll h = destination[1],v =  destination[0];
        string ans;
        memset(dp,-1,sizeof(dp));
        return word(h,v,k,ans,0);
    }
};
