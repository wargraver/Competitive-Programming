class Solution {
public:
    int maxSubarraySumCircular(vector<int>& a) {
         int i,j,k,n=a.size(),m,t=0;
        int sum=0,ans=1e9;
        for(i=0;i<n;i++){
            ans=min(ans,min(sum+a[i],a[i]));
            sum=min(sum+a[i],a[i]);
        }
        cout<<ans<<endl;
        int min_sum=ans;
        ans=-1e9;sum=0;
        for(i=0;i<n;i++){
            ans=max(ans,max(sum+a[i],a[i]));
            sum=max(sum+a[i],a[i]);
        }
        int max_sum=ans; cout<<max_sum<<endl;
        cout<<ans<<endl;sum=0;
        for(i=0;i<n;i++) sum+=a[i];
        cout<<sum<<endl;
        if(min_sum==sum) return max_sum;
        return max(max_sum,sum-min_sum);
    }
};
