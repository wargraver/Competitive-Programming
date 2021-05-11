int ans=0;
class Solution {
public:
    void merge(int st,int mid,int en,vector<int>& nums){
        vector<int> spare;
        int i = st,j = mid+1;
        j=mid+1;int kt=0;
        while(i<=mid && j<=en){
            long long int m = (long long int)nums[j],n=(long long int)nums[i];
            if(n>2*m) {ans+=(mid-i+1);j++;}
            else i++;
        }
        i=st;j=mid+1;
        while(i<=mid && j<=en){
            if(nums[i]<=nums[j]) {
                spare.push_back(nums[i]);
                i++;
            }
            else{
                spare.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
             spare.push_back(nums[i]);
             i++;
        }
        while(j<=en){
             spare.push_back(nums[j]);
            j++;
        }
        for(i=st;i<=en;i++) nums[i]=spare[i-st];
    }
    void mergesort(int st,int en,vector<int>& nums){
        if(st==en) return;
        int mid = (st+en)/2;
        mergesort(st,mid,nums);
        mergesort(mid+1,en,nums);
        merge(st,mid,en,nums);
    }
    int reversePairs(vector<int>& nums) {
        int i,j,k,n,m;ans=0;
        n=nums.size()-1;
        mergesort(0,n,nums);
        return ans;
    }
};
