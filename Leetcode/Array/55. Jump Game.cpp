class Solution {
public:
    bool canJump(vector<int>& a) {
        int i,j,k,n=a.size(),m,ct=0;
        int sub[30005]={0};
        sub[n-1]=1;int last=n-1;
        for(j=n-2;j>=0;j--){
            int max_jump=a[j];
            if(j+a[j]>=last){
                cout<<j<<" "<<a[j]<<" "<<last<<endl;
                last=j;
                sub[j]=1;
            }
            else sub[j]=-1;
        }
        for(i=0;i<n;i++) cout<<sub[i]<<" ";
        if(sub[0]==1) return 1;
        else return 0;
    }
};
