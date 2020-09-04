class Solution {
public:
    int minSubArrayLen(int s, vector<int>& a) {
        int i,j,k,n=a.size(),m,ct=0,sum=0,pref[500007]={0};
        pref[0]=0;cout<<pref[0]<<" ";
        for(i=1;i<=n;i++){
            pref[i]+=sum+a[i-1];
            sum=pref[i];
            cout<<pref[i]<<" ";
        }
        if(a.size()==0) return 0;
        int ans=1e9,ans2=1e9;
        for(i=0;i<n;i++){
            int low=i,high=n;
            int x=pref[i]+s;ans2=-1;
            while(low<=high){
            int mid=(low+high)/2;
                if(pref[mid]>=x) {ans2=mid;high=mid-1;}
                else low=mid+1;
            }
            if(ans2==-1) ans2=1e9;
            ans=min(ans2-i,ans);
        }
        if(pref[n-1]>=s) ans=min(n,ans);
        if(ans>1e5) return 0;
        return ans;
    }
};
