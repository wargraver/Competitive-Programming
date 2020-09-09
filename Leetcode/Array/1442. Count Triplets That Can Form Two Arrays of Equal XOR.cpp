class Solution {
public:
    int countTriplets(vector<int>& a) {
     int i,j,k,n,m,ct=0;
        n=a.size();
        int sum[n+1];k=0;sum[0]=0;
        for(i=1;i<=n;i++){
            sum[i]=k xor a[i-1];
         //  cout<<k<<" "<<a[i-1]<<" "<<sum[i]<<endl;
            k=sum[i];
        }
    for(i=1;i<=n;i++){
       for(j=i+1;j<=n;j++){
             k= sum[i-1] xor sum[j];
           if(k==0) {ct+=j-i;}
       } 
    }
        return ct;
    }
};
