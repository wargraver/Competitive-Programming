class Solution {
public:
    int check(int val,int n,int m,int k){
        int i,j,ct1=0,ct2=0,small,large;
        //Fetching no of values less than val
        for(j=0;j<n;j++){
            int low = 1,high = m;small=-1;
            while(low<=high){
                int mid =(low+high)/2;
                if((j+1)*mid<val){
                    low=mid+1;
                    small=mid;
                }
                else if((j+1)*mid>=val) high = mid-1;
            }
            if(small!=-1) ct1+=small;
        }
        //Fetching no of values less than or equal to val
        for(j=0;j<n;j++){
            int low =1,high = m;large=-1;
            while(low<=high){
                int mid = (low+high)/2;
                if((j+1)*mid<=val){
                    low=mid+1;
                    large = mid;
                }
                else high = mid-1;
            }
            if(large!=-1) ct2+=large;
        }
        //cout<<ct1<<" "<<ct2<<endl;
        if(ct1<k && ct2>=k) return 1;
        else if(ct2<k) return -1;
        else return 0;
    }
    int findKthNumber(int m, int n, int k) {
        int i,j,ct=0,ans=0;
        int low = 1,high = n*m;
        if(n==1 && m==1) return 1;
        while(low<=high){
            int mid = (low+high)/2;
           // cout<<mid<<" ";
            int t = check(mid,m,n,k);
            if( t==1){
                return mid;
            }
            else if(t==-1){
                low = mid+1;
            }
            else high = mid-1;
        }
        return ans;
    }
};
