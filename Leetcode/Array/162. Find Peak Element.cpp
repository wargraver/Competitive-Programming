class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low=0,high=nums.size()-1,i,j,k;int ans=0,n=nums.size();
        while(low<=high){
            int mid=(low+high)/2;
            if(mid!=0 && nums[mid]<nums[mid-1]) high=mid-1;
            else if(mid!=n-1 && nums[mid]<nums[mid+1]) low=mid+1;
            else {
                ans=mid;break;
            }
        }
        return ans;
    }
};
