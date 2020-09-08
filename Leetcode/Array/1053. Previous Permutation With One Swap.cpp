class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& a) {
        for(int n=a.size()-1;n>=1;n--){
            if(a[n]<a[n-1]){
                int val=-1;int k=0;
               for(int j=n;j<=a.size()-1;j++){
                   if(val<a[j] && a[j]<a[n-1]){
                       val=a[j];
                       k=j;
                   }
               }
                 int m=a[n-1];
                   a[n-1]=a[k];a[k]=m;
                   cout<<n-1<<" "<<k<<endl;
                break;
            }
        }
        return a;
    }
};
