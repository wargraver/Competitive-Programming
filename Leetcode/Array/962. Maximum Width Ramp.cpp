class Solution {
public:
    int maxWidthRamp(vector<int>& a) {
        int i,j,k,n=a.size(),m=0,ct=0;
        vector<pair<int,int>> vect;
        for(i=0;i<n;i++){
            vect.push_back({a[i],i});
        }
        sort(vect.begin(),vect.end());
        int min1=1e9;
        for(i=0;i<n;i++){
            m=max(vect[i].second-min1,m);
            min1=min(min1,vect[i].second);
        }
        return m;
    }
};
