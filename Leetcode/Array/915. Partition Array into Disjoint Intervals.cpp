class Solution {
public:
    int partitionDisjoint(vector<int>& a) {
        int i,j,k,n=a.size(),m,ct=0;
        int b[n],c[n];
        int a1=-1e9,a2=1e9;
        for(i=0;i<n;i++){
           a1=max(a1,a[i]);
           b[i]=a1;
        }
        for(i=n-1;i>=0;i--){
            a2=min(a2,a[i]);
            c[i]=a2;
        }
        for(i=1;i<n;i++){ 
            cout<<b[i-1]<<" "<<c[i]<<endl;
                if(b[i-1]<=c[i]) return i;
                else continue;
        }
        return 1;
    }
};
