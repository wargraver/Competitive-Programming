class Solution {
public:
    int minDifference(vector<int>& a) {
        sort(a.begin(),a.end());
        int n=a.size();
        int min1=a[0],max1=a[n-1];
        //chnaging left 3
        int diff=2e9+7;
        if(a.size()<=3) return 0;
        diff=min(max1-a[3],diff);
        diff=min(a[n-4]-min1,diff);
        diff = min(a[n - 2] - a[2], diff);
        diff = min(a[n - 3] - a[1], diff);
        return diff;
    }
};
