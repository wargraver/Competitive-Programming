class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int a[100000]={0};int sum=0;
        for(int i=0;i<S.size();i++){
            if(S[i]=='0') {
                a[i]+=(1+sum);
                sum=a[i];
            }
            else a[i]=sum;
         }
        //for(int i=0;i<S.size();i++) cout<<a[i]<<" ";
        int i,j,k,n,m;int ans=1e9;
        for(i=S.size()-1;i>=0;i--){
            int zeros_left=a[i];
            int ones_left=i+1-a[i];
            int zeros_right=a[S.size()-1]-a[i];
            ans=min(ans,ones_left+zeros_right);
        }
         int a1=a[S.size()-1],a2=S.size()-a[S.size()-1];
         int ans2= min(a1,a2);
        ans = min( ans,ans2);
        return ans;
        
    }
};
