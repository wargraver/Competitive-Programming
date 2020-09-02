class Solution {
public:
    int maxProduct(vector<int>& a) {
        int prev_max=a[0];
        int prev_min=a[0];
        int curr_max=a[0];int ans=a[0];
        for(int i=1;i<a.size();i++){
            curr_max=max(prev_max*a[i],max(prev_min*a[i],a[i]));
           int curr_min=min(prev_max*a[i],min(prev_min*a[i],a[i]));
            ans=max(ans,curr_max);
            prev_max=curr_max;
            prev_min=curr_min;
        }
        return ans;
    }
};
