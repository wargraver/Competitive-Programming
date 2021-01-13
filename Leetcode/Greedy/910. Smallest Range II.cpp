class Solution {
public:
    int smallestRangeII(vector<int>& a, int K) {
        int i,j,k,n,m,ct=0;
        n= a.size();
        sort(a.begin(),a.end());
        int min1=1e9;
        if(n==1) return 0;
        min1=min(a[n-1]-a[0],min1);
        for(i=0;i<n-1;i++){
            int high=max(a[n-1]-K,a[i]+K);
            int low=min(a[0]+K,a[i+1]-K);
            min1=min(min1,high-low);
        }
        return min1;
    }
};
