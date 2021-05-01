class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i,j,k,n,m;
        n=nums.size();
        for(i=0;i<nums.size();i++){
            while(nums[i]<=n && nums[i]>0 && nums[i]!=i+1){
                 k = nums[nums[i]-1];
                if(k==nums[i]) break;
                nums[nums[i]-1]=nums[i];
                nums[i]=k;
            }
        }
       for(i=0;i<n;i++) cout<<nums[i]<<" ";
        for(i=0;i<n;i++){
            if(nums[i]!=i+1) return i+1;
        }
        return nums[n-1]+1;
    }
};
