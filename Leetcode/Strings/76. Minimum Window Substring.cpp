int n;
class Solution {
public:
    int match(int dp[123],int freq[123],int i){
        for(int j=0;j<123;j++){
            if(freq[j]>dp[j]) return -1; 
        }
        return 1;
    }
    string minWindow(string s, string t) {
        int i,j,k,m,ct=0;
        n = s.size();
      //  cout<<n<<endl;
        int freq[123]={0};
        int dp[123];
        memset(dp,0,sizeof(dp));
        int ans=1e9;
        for(i=0;i<t.size();i++) freq[t[i]-'A']++;
        int st=0,en=0;
        i=0;int flag=0;
        string str;int m1=-1,m2=-1;
        while(i<n && st<n){
            if(flag==0) dp[s[i]-'A']++;
            if(match(dp,freq,i)==1){
                if(i-st+1<ans){
                    ans = i-st+1;
                    m1 = st;m2 =i;
                }
                //cout<<s[st]<<" "<<s[i]<<" ";
                 //cout<<st<<" "<<i<<endl;
               // cout<<s[st]-'A'<<endl;
                dp[s[st]-'A']--;
                st++;
                flag=1;
                    //for(j=0;j<26;j++) dp[st][j]=0;
                }
                else {i++;flag=0;}
        }
        if(m1==-1) return str;
        for(i=m1;i<=m2;i++) str += s[i];
        //cout<<ans<<endl;
        return str;
       // return ans;
    }
};
