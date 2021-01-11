long long int max1=1e9+7;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        long long int i,j,k,n,m,ct=0;set<string> dict;
        for(i=0;i<wordDict.size();i++) {
            dict.insert(wordDict[i]);
        }
        n=s.size();
        long long int dp[n+5];
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++){
            for(j=0;j<=i;j++){
                string temp;
                for(k=j;k<=i;k++) temp+=s[k];
                if(dict.find(temp)!=dict.end()){
                    if(j>0) dp[i]+=dp[j-1]%max1;
                    else dp[i]+=1;
                }
            }
        }
        cout<<dp[n-1]<<endl;
        if(dp[n-1]>0) return true;
        else return false;
    } 
};
