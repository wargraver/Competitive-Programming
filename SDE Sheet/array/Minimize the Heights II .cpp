class Solution{   
public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr,arr+n);
       int i,j,m=0;int ans=1e9;
       for(i=0;i<n;i++){
           if(arr[i]-k>=0 && i>=1){
               int min1=min(arr[0]+k,min(arr[i]-k,arr[n-1]-k));
               int max1=max(arr[i-1]+k,arr[n-1]-k);
               ans=min(ans,max1-min1);
           }
           else ans=min(ans,arr[n-1]-arr[0]);
       }
       return ans;
    }
};
