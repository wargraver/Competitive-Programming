class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i,j,k,n=(int)nums.size(),ct=0,sum;
        int l=2,r;
        if(n==0) return 0;
        else if(n==1) return 1;
        for(r=2;r<n;r++){
            if(nums[l-2]!=nums[r]){
                nums[l]=nums[r];
                l++;
            }
        }
        return l;
    }
   
};
