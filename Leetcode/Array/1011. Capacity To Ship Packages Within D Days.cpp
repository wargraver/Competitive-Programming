int check(int mid,vector<int>& w,int D){
    int i,ct=0,sum=0;
    for(i=0;i<w.size();i++){
        if(sum+w[i]<=mid){
            sum+=w[i];
            if(i==w.size()-1) ct++;
        }
        else if(w[i]<=mid && sum+w[i]>mid){
            sum=w[i];
            ct++;
            if(i==w.size()-1) ct++;
        }
        else if(w[i]>mid) return 0;
    }
    cout<<mid<<" "<<ct<<endl;
    if(ct<=D) return 1;
    else return 0;
}
class Solution {
public:
    int shipWithinDays(vector<int>& w, int D) {
        int sum=0;
        for(int i=0;i<(int)w.size();i++) sum+=w[i];
        int l=1,r=sum,ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid,w,D)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};
