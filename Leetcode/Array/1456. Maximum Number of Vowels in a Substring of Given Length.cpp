class Solution {
public:
    int maxVowels(string s, int k) {
        int i,j,n,m,ct=0;
        n=s.size()-1;
        int ans=0;
        for(i=0;i<k;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') ans++;
        }
        ct=ans;
       // cout<<ans<<endl;
        for(i=k;i<=n;i++){
             if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') ct++;
             if(s[i-k]=='a'||s[i-k]=='e'||s[i-k]=='i'||s[i-k]=='o'||s[i-k]=='u') ct--;
            ans=max(ans,ct);
        }
        return ans;
    }
};
