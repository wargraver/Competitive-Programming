int oth(vector<int> arr, int l, int m, int h) 
{   // Include elements on left of mid. 
    int sum = 0; 
    int left_sum = INT_MIN; 
    for (int i = m; i >= l; i--) 
    { 
        sum = sum + arr[i]; 
        if (sum > left_sum) 
          left_sum = sum; 
    } 
    // Include elements on right of mid 
    sum = 0; 
    int right_sum = INT_MIN; 
    for (int i = m+1; i <= h; i++) 
    { 
        sum = sum + arr[i]; 
        if (sum > right_sum) 
          right_sum = sum; 
    } 
    return max(left_sum + right_sum, max(left_sum, right_sum)); 
} 
int fun(vector<int> nums,int st,int en){
    if(st==en) return nums[st];
    else{
        int mid=(st+en)/2;
        int j= max(fun(nums,st,mid),fun(nums,mid+1,en));
        int k=oth(nums,st,mid,en);
        return max(j,k);
    }
}
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size()-1;
        return fun(nums,0,n);
    }
};
