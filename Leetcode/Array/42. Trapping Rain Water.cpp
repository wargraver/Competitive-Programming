class Solution {
public:
    int trap(vector<int>& height) {
        int i,j,k,n,ct=0;
        int lmax=-1,rmax=-1;
        n=height.size();
        int l=0,r=n-1;
        int ans=0;
        while(l<=r){
            if(height[l]<=height[r]){
                if(lmax>=height[l]){
                    ans+=min(lmax,height[r])-height[l];
                }
                else lmax=height[l];
                l++;
            }
            else{
                if(rmax>=height[r]){
                    ans+=min(rmax,height[l])-height[r];
                }
                else rmax=height[r];
                r--;
            }
        }
        return ans;
    }
};
