long long int mod = 1e9+7;
class Solution {
public:
    int distinctSubseqII(string s) {
        map<char,long long int> dict;
        long long int dp[s.size()+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(long long int i=1;i<=s.size();i++){
            if(dict.find(s[i-1])==dict.end()){
                dict.insert({s[i-1],i-1});
                dp[i] = (2*dp[i-1])%mod;
            }
            else{
                auto k = dp[dict[s[i-1]]];
                dp[i] = ((2*dp[i-1])%mod+mod-k)%mod;
                dict[s[i-1]]=i-1;
            }
           // cout<<dp[i]<<endl;
        }
        return (dp[s.size()]-1)%mod;
    }
};
